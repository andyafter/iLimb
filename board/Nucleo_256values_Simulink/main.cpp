// Debug version that outputs ASCII at a slow 20Hz
// Has a feature to measure amount of time needed to output 100 frames

// Please select NUCLEO-F303K8 as the target device

#include "mbed.h"

#define FPS
#define BAUD         115200
#define N_CHANNELS  256

AnalogIn in(A0);

DigitalOut mux_ch0(D6), mux_ch1(D4), mux_ch2(D8), mux_ch3(D9);
DigitalOut mux_en(D5);

DigitalOut reg_din(D10);
DigitalOut reg_clk(D11);
DigitalOut reg_clr(D12);

DigitalOut led(D13);
Timer timer;
Serial pc(USBTX,USBRX);

int in_value = 0;
uint8_t mux_ch_map[16] = {6,7,5,4,0,1,2,3,14,12,13,15,8,9,11,10};

int counter = 0;
int count_index =0;
int array_mx[256];
int tmr_start, tmr_end;
uint8_t mux_val;

int main()
{
    for (int i=0; i < 256; i++)
    {array_mx[i] =0;}
    
     pc.baud(BAUD);
    
    //pc.printf("Nucleo 16x16 basic raster\r\n");
    //pc.printf("Initializing...\r\n");
    // reset registers and intialize peripherals
    mux_en = 0;  // power off mux
    mux_ch0 = 0;
    mux_ch1 = 0;
    mux_ch2 = 0;
    mux_ch3 = 0;
    led = 0;

    reg_din = 0;
    reg_clr = 0; // reset register
    reg_clk = 0;

    wait_ms(100);
    mux_en = 1;
    reg_clr = 1;
    wait_ms(100);
    //pc.printf("Clock speed: %d\r\n", SystemCoreClock);
    //pc.printf("Started scanning\r\n");

    // do a single read using original read_u16 code
    in_value = in.read_u16();
    
    // benchmark
    timer.start();
    tmr_start = timer.read_us();

    while(1) {
        
        for (int row=0; row<16; row++) {
//             0 connects trace to ground. Only 1 grounded trace per cycle is needed.
      
            if(row == 0) {
               // pc.printf("\n");
             //pc.printf("r,");
                led = !led; // blink to indicate operation
                reg_din.write(1);
            } else {
                reg_din.write(0);
            }

            // bit-bashing the register clock
            reg_clk.write(1);
            
            // send out data while fulfilling t_hold of register
            wait_us(1);
            
            // 2nd part of bit-bashing clock
            reg_clk.write(0);
/*
#ifdef FPS            
            // benchmarking only if FPS is defined
            if(row == 0) {
                counter++;

                if(counter >= 100) {
                    tmr_end = timer.read_us();
                    pc.printf("Elapsed: %d us after %d frames\r\n", tmr_end-tmr_start, counter);
                    wait_ms(5000);
                    tmr_start = timer.read_us();
                    counter = 0;
                }
            }
#endif*/
            for (int col=0; col<16; col++) {
                
                mux_val = mux_ch_map[15-col];
                mux_ch0.write(mux_val & 0x01);
                mux_ch1.write((mux_val >> 1) & 0x01);
                mux_ch2.write((mux_val >> 2) & 0x01);
                mux_ch3.write((mux_val >> 3) & 0x01);
                wait_us(1);
                in_value = in.read_u16()>>4;
                
                //pc.printf("%d,",in_value);
                array_mx[count_index] = in_value; 
                count_index = count_index+1;
            
            }                       
        }
        if (count_index ==256)
        {
           count_index = 0;
           pc.printf("\n");
           pc.printf("r,");
           for (int i =0; i<256; i++){
               pc.printf("%d,",array_mx[i]);
            }
           pc.printf("r");
        }
    }
}

