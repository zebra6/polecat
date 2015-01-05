#pragma once

/*function prototypes*/
void run_tests( void );

int set_bit( int var, int bit_num );
int clear_bit( int var, int bit_num );
int test_bit( int var, int bit_num );
int set_rightmost_one_zero( int val );
int set_rightmost_zero_one( int val );
int bitwise_abs( int val );
void swap_no_temp_var( int* a, int* b );
int round_down_mul_eight( int val );
int round_up_mul_eight( int val );
int round_down_power_two( int val );
int round_up_power_two( int val );

/*accessory functions*/
void print_bytes_bin( void* start, int num_bytes );


