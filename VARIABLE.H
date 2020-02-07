
#ifndef VARIABLE_H
#define VARIABLE_H

static bit   inc @((unsigned) &PORTC*8+0); //input
static bit   dec @((unsigned) &PORTC*8+2);//input//read pin of lcd
static bit   menu @((unsigned) &PORTA*8+4); //input

static bit   En_lcdlight @((unsigned) &PORTD*8+2);  //output
//static bit   mic @((unsigned) &PORTD*8+3);	//OUTPUT

static bit   MODE_KEY @((unsigned) &PORTC*8+5);//input
static bit   PHASE_KEY @((unsigned) &PORTB*8+1);//input

 static bit   RELAY1  @((unsigned) &PORTB*8+0); //output
static bit   RELAY4  @((unsigned) &PORTE*8+1); //output//2
static bit   RELAY2  @((unsigned) &PORTC*8+1); //output//3
static bit   RELAY3  @((unsigned) &PORTE*8+2); //output//4
//static bit   RELAY5  @((unsigned) &PORTB*8+2); //output
static bit   Reset_Key  @((unsigned) &PORTB*8+2); //output

static bit   LED_3PH  @((unsigned) &PORTB*8+7); //output
static bit   LED_2PH  @((unsigned) &PORTB*8+6); //output
static bit   LED_OL  @((unsigned) &PORTB*8+5); //output
static bit   LED_DR  @((unsigned) &PORTB*8+4); //output
static bit   LED_ZAMPS @((unsigned) &PORTB*8+3); //output

#define ON 1
#define OFF 0
//static bit   capacitor_relay   @((unsigned) &PORTB*8+2); //output

unsigned int set_val,max_3ph_rvolt,high_voltage_3ph,high_voltage_2ph;
unsigned int over_3ph_amps,over_2ph_amps,zero_amps_timer,low_voltage_3ph;
unsigned int dryrun_3ph_amps,dryrun_2ph_amps,power_on_delay,low_voltage_2ph;
unsigned int dry_run_scantime,over_load_scantime,star_delay_time,starting_capacitor_delay;
unsigned int dry_run_restarttimer,stored_value,power_up_timer;
unsigned int rvolt,yvolt,bvolt,msec,sec,star_delay_timer,ramps;
unsigned int over_load_timer,zero_amps_scan_timer,dry_amps_scan_timer;
unsigned int drurun_restart,temp_val;
unsigned int ry_volt,yb_volt,br_volt,ledbacklight_en_time;
unsigned int starting_capacitor_delay_timer,drurun_restart1;
unsigned char msec_timer1,secc,running,set_menu,drs,temp_diff1,temp_diff2;
unsigned int yamps,bamps,diff_3ph_volt;
unsigned char max_motor_run_sec,dry_rst_scan_timer_total_min;
unsigned int power_up_timer_min,star_delay_timer_min,over_load_timer_min,zero_amps_scan_timer_min,dry_amps_scan_timer_min;
unsigned int power_up_timer_total_min,star_delay_total_timer_min,over_load_total_timer_min,zero_amps_scan_timer_total_min,dry_amps_scan_timer_total_min;
unsigned int max_motor_run_min,starting_capacitor_delay_min,starting_capacitor_delay_total_min;
bit max_runtime,two_phase_ok;

unsigned char sd_delay_hour,sd_delay_min,sd_delay_sec,ignor;
unsigned char hour_set,min_set,sec_set;
unsigned char sd_delay_hour,sd_delay_min,sd_delay_sec;
unsigned char scr_delay_hour,scr_delay_min,scr_delay_sec;
unsigned char run_delay_hour,run_delay_min,run_delay_sec;
unsigned char cyclicon_sec,cyclicon_min,cyclicon_MIN,cyclicon_HRS,cyclicof_MIN,cyclicof_HRS;
unsigned char cyclicof_min,cyclicof_sec,ok,r_bit=1,y_bit,b_bit;


unsigned char rtc1on_delay_hour,rtc1on_delay_min;
unsigned char rtc2on_delay_hour,rtc2on_delay_min;
unsigned char rtc3on_delay_hour,rtc3on_delay_min;
unsigned char rtc4on_delay_hour,rtc4on_delay_min;
unsigned char rtc1of_delay_hour,rtc1of_delay_min;
unsigned char rtc2of_delay_hour,rtc2of_delay_min;
unsigned char rtc3of_delay_hour,rtc3of_delay_min;
unsigned char rtc4of_delay_hour,rtc4of_delay_min;
unsigned char rtc5on_delay_hour,rtc5on_delay_min;
unsigned char rtc5of_delay_hour,rtc5of_delay_min;
unsigned char rtc6on_delay_hour,rtc6on_delay_min;
unsigned char rtc6of_delay_hour,rtc6of_delay_min;
unsigned char rtc7on_delay_hour,rtc7on_delay_min;
unsigned char rtc7of_delay_hour,rtc7of_delay_min;
unsigned char rtc8on_delay_hour,rtc8on_delay_min;
unsigned char rtc8of_delay_hour,rtc8of_delay_min;
unsigned char rtc9on_delay_hour,rtc9on_delay_min;
unsigned char rtc9of_delay_hour,rtc9of_delay_min;
unsigned char rtc10on_delay_hour,rtc10on_delay_min,inca=0,inc1=0,menua=0,menu1=0;;
unsigned char rtc10of_delay_hour,rtc10of_delay_min,hv_fault,lv_fault;
unsigned char dff_volt_timerbit,diff_volt_bit,rtc_sec,rtc_min,rtc_hour;
unsigned int  diff_volt_scan_timer;
unsigned char on_delay_hour,on_delay_min,on_delay_sec;
unsigned char olscan_delay_hour,olscan_delay_min,olscan_delay_sec;
unsigned char drscan_delay_hour,drscan_delay_min,drscan_delay_sec;
unsigned char drrst_delay_hour,drrst_delay_min,drrst_delay_sec;
unsigned char maxtime_delay_hour,maxtime_delay_min,maxtime_delay_sec;
unsigned int maxtime_delay_total_min,maximum_phase_voltage;
unsigned char lowvoltage_scan_timer_bit,highvoltage_scan_timer_bit;
unsigned char lowvoltage_scan_time,highvoltage_scan_time;


unsigned char rec=0,rec1,on_t,tone_sec,dsec,disec;
//unsigned char mob_number[35];
//unsigned char rec_mob_number[25];
//unsigned char temp_mob_number[11];
//unsigned char temp_dtmf_mob_number[11];

unsigned char mob_number1[15];
unsigned char mob_number2[15];
unsigned char mob_number3[15];
unsigned char mob_number4[15];

unsigned char firstSimCheck,alertForSim;
char GsmSimInit[20],GsmSimInitLen=0;

unsigned int motor_min;
unsigned char motor_sec,rtcmode_enable,rec_tme[25],nw_date;

unsigned char cyclicon_delay_hour,rtc_dat,rtc_mon,rtc_year;
unsigned char cyclicon_delay_min;
unsigned char cyclicon_delay_sec;

unsigned char cyclicof_delay_hour;
unsigned char cyclicof_delay_min;
unsigned char cyclicof_delay_sec,dtmf_tone;

unsigned int cyclicon_delay_total_min;
unsigned int cyclicof_delay_total_min,diff_amp,diff_amp_bit=0,diff_cur;
unsigned char calon_ring;
unsigned char rtc_secc=10,rtc_minn=59,rtc_hourr=23,user;

// ring process
unsigned char rec_ring[10],ring_len,ring_count;
unsigned char IMEI_Num[20],MSG_CHECK_BUF[5];

int ii;
char b1[10];
//unsigned char aa3[10]={0xd8,0xdb,0xde,0};

char motoron=0,temp_motoron=0;
bit on_t1,on_t2,on_t3,on_t4,on_t5,on_t6,on_t7,on_t8,on_t9;
bit ph_changed,three_phase_ok,threeph_lv,twoph_lv,star_delta_timerbit;
bit threeph_hv,twoph_hv,start_poweruptimer,poweron_timer_bit,over_loadbit,over_load_timerbit;
bit zero_amps_timerbit,zero_amps_bit,dryrun_amps_timerbit,dry_amps_scan_timerbit;
bit dryrun_amps_bit,dryrun_restarttimer_bit,cur,dsp;
bit starting_capacitor_delay_timer_bit=0,ms,incc,load_on,ring;
bit mode_key_state,phase_key_state,lock,menu_ok,load_loack,rec_bit,no_match,mode_key_state_init;
bit cyclic_tim_on;
bit cyclic_tim_of;
bit maxtimoff;
bit rtcof,dtmf_bit;
unsigned char cyclictimoff;
bit smson_bit,dtmf_on,call;
bit motoron_sms_bit,pwr_on_bit;
bit callon;
bit cyclictimoff_1;
bit fault,motoron_mcall;
bit motor_smsof;
bit b_phch;
bit rtc_tim1,rtc_tim2,rtc_tim3,rtc_tim4,diff,ol,da,za,dra,thp,twp;

bit initializations=0;

bit RESET_Bit;

//bit phase_error_bit=0;

unsigned int low_voltage_scan_time,high_voltage_scan_time,diff_voltage_scan_time;

unsigned char mobileno1_enable_bit,mobileno2_enable_bit,mobileno3_enable_bit,mobileno4_enable_bit;


unsigned char rec_mob,rec_buf,rec_buffer[120],rec_mobile[40],motor,mode,phase;
unsigned char loop,rtc_set=1;
unsigned char rtc_date,rtc_month,rtc_year,set_bit=0,cy_bit,volt_bit;

//tower checking
unsigned char FirstTowerCheck;
unsigned char signalCheckOn,signalCheck[9],signalCheckLen;
unsigned char MSG_ERR_CHECK[6],MSG_ERR_CHECK_Len;
unsigned int signalStrength;

//carry check
unsigned char carry[10],carry_len;
unsigned char pow_sec;
unsigned char IGNORE_FAULT;

unsigned int Sec_0,Min_0,err_;
unsigned int Ast,AstDisplay,Ast_Min,Ast_Sec,PowSec;

unsigned int Wdt_Reset_timer,Wdt_Reset_sec;
unsigned int init_phase_bit=0;
//unsigned int SimCard=2;
bit displayBit,Message_ok;
//unsigned int SimCount;

unsigned int SimCard,sim_check_var,simcheckvar,msgSendbd,user_ph_disable=0,okk,SimCount;

unsigned int manual_rst_count,temp_manual_rst_count,Thershould_voltage_level,Message_send_error_Count;


unsigned int Measurement_On;
unsigned int MSG_CHECK_BUF_len,MSG_rec_len,msg_receive;
unsigned char MSG_rec[5];
unsigned int Onetimer_delay_hour,Onetimer_delay_min,Onetimer_on,Onetimer_delay_total_min,Onetimer_on_min,Onetimer_sec,Onetimer_on_MIN,Onetimer_on_HRS;

unsigned int Otc_Off=0;
unsigned int AT_sec,AT_min;

bit Ring_ring,Off_key_bit,Two_Phase_Fault_Send;
bit At_bit=0;
unsigned int unknown_BIT=0;


unsigned char Received_Mobile_Number[10];

unsigned int Message_sent_Count;
bit Message_Send_bit;
bit Power_On_Message_Flag;




bit PowerOn_bit,
	Three_Phase_Line_bit,
	Two_Phase_Line_bit,
	IMEI_bit,
	Change_bit,
	Single_phase_Fault_bit;

unsigned int Cut_Off_Phase;





bit Auto_On_bit,
Setting_Mode_Timer_bit,
Blink,
Setting_bit,
Manual_OTC_bit,
Settings_delay_bit,

Starter_Trip_bit,
Dry_Run_bit,
Over_Load_bit,
Diff_Amps_bit,
High_Voltage_bit,
Low_Voltage_bit,
Diff_Voltage_bit,
PowerOn_bit,

Setting_Mode_Timer_bit,
Sendings_Status_bit,
Init_Sim_Registration_Signal_bit,
GSM_Error_bit,
Auto_Off_Send_bit;





unsigned int Setting_Mode_Timer,
Division,
MODULUS,
Blink_sec,
Auto_On_Sec,
Setting_Mode_Timer_Seconds,
Previous_value,
OTC_cleared_value,
Auto_On_Timer,
Exit_Settings_Timer;

int value;


bit RTC_Time_1_bit,
RTC_Time_2_bit,
RTC_Time_3_bit,
Send_Power_On_Message_bit,
SMS_Status_Check_Bit,
Registration_Status_bit,
SIM_Registration_bit,
SIM_Check_bit;

unsigned int RTC_Time_1_Hours,
RTC_Time_2_Hours,
RTC_Time_3_Hours,

RTC_Time_1_Minutes,
RTC_Time_2_Minutes,
RTC_Time_3_Minutes,

RTC_Time_1_Sent,
RTC_Time_2_Sent,
RTC_Time_3_Sent,

Time_Delay_1,
Time_Delay_2,
Time_Delay_3,

Current_RTC_Time,

SMS_Status_Buffer_Value,
Register_Status_Buffer_Value,
SIM_Registration_Counter,
Registration_Check_Counter,
SIM_Check_Buffer_Value;

unsigned char SMS_Status_Buffer[6],
Register_Status_Buffer[10],
SIM_Check_Buffer[13];

int R_Amps,
Y_Amps,
B_Amps;
#endif
