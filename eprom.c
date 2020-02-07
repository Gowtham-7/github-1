#include"Lcd.h"
#include"VARIABLE.H"
#include"EPROM.H"

unsigned int eprom_read(unsigned char);
void eprom_write(unsigned char,unsigned int);
unsigned int Eprom_read(unsigned char);
void Eprom_write(unsigned char,unsigned int);
unsigned int stored_value;
unsigned int eprom_read(unsigned char location)
{
	stored_value=(EEPROM_READ(location)*4);delay(50);
	stored_value+=EEPROM_READ(location+1);delay(50);
	return(stored_value);
}
void eprom_write(unsigned char location,unsigned int value)
{
	EEPROM_WRITE(location,value/4);delay(50);
	EEPROM_WRITE(location+1,value%4);delay(50);
}

unsigned int Eprom_read(unsigned char location)
{
	stored_value=(Eeprom_Read1(location)*4);delay(500);
	stored_value+=Eeprom_Read1(location+1);delay(500);
	return(stored_value);
}
void Eprom_write(unsigned char location,unsigned int value)
{
	Eeprom_Write1(location,value/4);delay(500);
	Eeprom_Write1(location+1,value%4);delay(500);
}
void read()
{
		Power_On_Message_Flag=EEPROM_READ(111);
		if(eeprom_read(100)!='A' && eeprom_read(200)!='K'){

		        EEPROM_WRITE(241,240);
				low_voltage_3ph=350;
				eprom_write(0,low_voltage_3ph);
				high_voltage_3ph=500;
				eprom_write(2,high_voltage_3ph);
				diff_3ph_volt=30;
				eprom_write(4,diff_3ph_volt);
				dryrun_3ph_amps=100;
				eprom_write(6,dryrun_3ph_amps);
				over_3ph_amps=180;
				eprom_write(8,over_3ph_amps);
				diff_amp=30;
				eprom_write(101,diff_amp);
				ignor='N';
				eprom_write(102,ignor);

				user_ph_disable=EEPROM_READ(174);
				mode_key_state=EEPROM_READ(175);
				Thershould_voltage_level=175;


				low_voltage_2ph=350;
				eprom_write(10,low_voltage_2ph);
				high_voltage_2ph=500;
				eprom_write(12,high_voltage_2ph);
				dryrun_2ph_amps=80;
				eprom_write(14,dryrun_2ph_amps);
				over_2ph_amps=200;
				eprom_write(16,over_2ph_amps);

				dry_run_scantime=3;
				eprom_write(18,dry_run_scantime);
				over_load_scantime=3;
				eprom_write(20,over_load_scantime);
				zero_amps_timer=3;
				eprom_write(21,zero_amps_timer);
				low_voltage_scan_time=3;
				eprom_write(22,low_voltage_scan_time);
				high_voltage_scan_time=3;
				eprom_write(23,high_voltage_scan_time);
				diff_voltage_scan_time=3;
				eprom_write(25,diff_voltage_scan_time);
				star_delay_time=3;
				eprom_write(24,star_delay_time);
				starting_capacitor_delay=5;
				eprom_write(26,starting_capacitor_delay);
				power_on_delay=0;
				eprom_write(28,power_on_delay);
				dry_run_restarttimer=1;
				eprom_write(36,dry_run_restarttimer);
				manual_rst_count=1;
				temp_manual_rst_count=1;
				EEPROM_WRITE(30,manual_rst_count);



				cyclicon_delay_hour=0;
				EEPROM_WRITE(38,cyclicon_delay_hour);
				cyclicon_delay_min=0;
				EEPROM_WRITE(40,cyclicon_delay_min);
				cyclicof_delay_hour=0;
				EEPROM_WRITE(42,cyclicof_delay_hour);
				cyclicof_delay_min=0;
				EEPROM_WRITE(44,cyclicof_delay_min);


				for(loop=0;loop<=9;loop++)
				{
				mob_number2[loop]=0;delay(10);
				EEPROM_WRITE(103+loop,mob_number2[loop]);
				mob_number1[loop]=0;delay(10);
				EEPROM_WRITE(104+loop,mob_number1[loop]);
				mob_number3[loop]=0;delay(10);
				EEPROM_WRITE(105+loop,mob_number3[loop]);
				mob_number4[loop]=0;delay(10);
				EEPROM_WRITE(106+loop,mob_number4[loop]);
				}
					mobileno1_enable_bit=0;
					EEPROM_WRITE(107,mobileno1_enable_bit);
					mobileno2_enable_bit=0;
					EEPROM_WRITE(108,mobileno2_enable_bit);
					mobileno3_enable_bit=0;
					EEPROM_WRITE(109,mobileno3_enable_bit);
					mobileno4_enable_bit=0;
					EEPROM_WRITE(110,mobileno4_enable_bit);


					rtc1on_delay_hour=0;
					EEPROM_WRITE(46,rtc1on_delay_hour);

					rtc1on_delay_min=0;
					EEPROM_WRITE(47,rtc1on_delay_min);


					rtc1of_delay_hour=0;
					EEPROM_WRITE(48,rtc1of_delay_hour);


					rtc1of_delay_min=0;
					EEPROM_WRITE(49,rtc1on_delay_min);


					rtc2on_delay_hour=0;
					EEPROM_WRITE(51,rtc2on_delay_hour);

					rtc2on_delay_min=0;
					EEPROM_WRITE(52,rtc2on_delay_min);

					rtc2of_delay_hour=0;
					EEPROM_WRITE(53,rtc2of_delay_hour);

					rtc2of_delay_min=0;
					EEPROM_WRITE(54,rtc2of_delay_min);


					rtc3on_delay_hour=0;
					EEPROM_WRITE(56,rtc3on_delay_hour);

					rtc3on_delay_min=0;
					EEPROM_WRITE(57,rtc3on_delay_min);

					rtc3of_delay_hour=0;
					EEPROM_WRITE(58,rtc3of_delay_hour);


					rtc3of_delay_min=0;
					EEPROM_WRITE(59,rtc3of_delay_min);

					rtc4on_delay_hour=0;
					EEPROM_WRITE(61,rtc4on_delay_hour);

					rtc4on_delay_min=0;
					EEPROM_WRITE(62,rtc4on_delay_min);

					rtc4of_delay_hour=0;
					EEPROM_WRITE(63,rtc4of_delay_hour);

					rtc4of_delay_min=0;
					EEPROM_WRITE(64,rtc4of_delay_min);

					rtc5on_delay_hour=0;
					EEPROM_WRITE(66,rtc5on_delay_hour);

					rtc5on_delay_min=0;
					EEPROM_WRITE(67,rtc5on_delay_min);

					rtc5of_delay_hour=0;
					EEPROM_WRITE(68,rtc5of_delay_hour);

					rtc5of_delay_min=0;
					EEPROM_WRITE(69,rtc5of_delay_min);

					rtc6on_delay_hour=0;
					EEPROM_WRITE(71,rtc6on_delay_hour);

					rtc6on_delay_min=0;
					EEPROM_WRITE(72,rtc6on_delay_min);

					rtc6of_delay_hour=0;
					EEPROM_WRITE(73,rtc6of_delay_hour);

					rtc6of_delay_min=0;
					EEPROM_WRITE(74,rtc6of_delay_min);

					rtc7on_delay_hour=0;
					EEPROM_WRITE(76,rtc7on_delay_hour);

					rtc7on_delay_min=0;
					EEPROM_WRITE(77,rtc7of_delay_min);

					rtc7of_delay_hour=0;
					EEPROM_WRITE(78,rtc7of_delay_hour);

					rtc7of_delay_min=0;
					EEPROM_WRITE(79,rtc7of_delay_min);

					rtc8on_delay_hour=0;
					EEPROM_WRITE(81,rtc8on_delay_hour);

					rtc8on_delay_min=0;
					EEPROM_WRITE(82,rtc8on_delay_min);

					rtc8of_delay_hour=0;
					EEPROM_WRITE(83,rtc8of_delay_hour);

					rtc8of_delay_min=0;
					EEPROM_WRITE(84,rtc8of_delay_min);

					rtc9on_delay_hour=0;
					EEPROM_WRITE(86,rtc9on_delay_hour);
					rtc9on_delay_min=0;
					EEPROM_WRITE(87,rtc9on_delay_min);
					rtc9of_delay_hour=0;
					EEPROM_WRITE(88,rtc9of_delay_hour);
					rtc9of_delay_min=0;
					EEPROM_WRITE(89,rtc9of_delay_min);

					rtc10on_delay_hour=0;
					EEPROM_WRITE(91,rtc10on_delay_hour);
					rtc10on_delay_min=0;
					EEPROM_WRITE(92,rtc10on_delay_min);
					rtc10of_delay_hour=0;
					EEPROM_WRITE(93,rtc10of_delay_hour);
					rtc10of_delay_min=0;
					EEPROM_WRITE(94,rtc10of_delay_min);

					cyclic_tim_of=1;
    				cyclic_tim_on=0;
					cyclicon_min=0;
					cyclictimoff=1;rtcmode_enable=0;
					user=0;
		}

		else
			{
				low_voltage_3ph=eprom_read(0);

				high_voltage_3ph=eprom_read(2);
				diff_3ph_volt=eprom_read(4);
				dryrun_3ph_amps=eprom_read(6);
				over_3ph_amps=eprom_read(8);

				low_voltage_2ph=eprom_read(10);
				high_voltage_2ph=eprom_read(12);
				dryrun_2ph_amps=eprom_read(14);
				over_2ph_amps=eprom_read(16);

				dry_run_scantime=eprom_read(18);
				over_load_scantime=eprom_read(20);
				low_voltage_scan_time=eprom_read(22);
				star_delay_time=eprom_read(24);
				starting_capacitor_delay=eprom_read(26);
				power_on_delay=eprom_read(28);

				manual_rst_count=EEPROM_READ(30);
				temp_manual_rst_count=manual_rst_count;

				Thershould_voltage_level=eprom_read(32);
				dry_run_restarttimer=eprom_read(36);

				cyclicon_delay_hour=eprom_read(38);
				cyclicon_delay_min=eprom_read(40);
				cyclicof_delay_hour=eprom_read(42);
				cyclicof_delay_min=eprom_read(44);

				diff_amp=eprom_read(101);
				ignor=eprom_read(102);
				user_ph_disable=EEPROM_READ(174);
				mode_key_state=EEPROM_READ(175);



				zero_amps_timer=dry_run_scantime;//eprom_read(18);
				high_voltage_scan_time=low_voltage_scan_time;
				diff_voltage_scan_time=low_voltage_scan_time;



				for(loop=0;loop<=9;loop++)
				{
				mob_number2[loop]=eeprom_read(104+loop);delay(10);
				mob_number1[loop]=eeprom_read(103+loop);delay(10);
				mob_number3[loop]=eeprom_read(105+loop);delay(10);
				mob_number4[loop]=eeprom_read(106+loop);delay(10);
				}
					mobileno1_enable_bit=eeprom_read(107);
					mobileno2_enable_bit=eeprom_read(108);
					mobileno3_enable_bit=eeprom_read(109);
					mobileno4_enable_bit=eeprom_read(110);


					rtc1on_delay_hour=EEPROM_READ(46);
					rtc1on_delay_min=EEPROM_READ(47);
					rtc1of_delay_hour=EEPROM_READ(48);
					rtc1of_delay_min=EEPROM_READ(49);

					rtc2on_delay_hour=EEPROM_READ(51);
					rtc2on_delay_min=EEPROM_READ(52);
					rtc2of_delay_hour=EEPROM_READ(53);
					rtc2of_delay_min=EEPROM_READ(54);

					rtc3on_delay_hour=EEPROM_READ(56);
					rtc3on_delay_min=EEPROM_READ(57);
					rtc3of_delay_hour=EEPROM_READ(58);
					rtc3of_delay_min=EEPROM_READ(59);

					rtc4on_delay_hour=EEPROM_READ(61);
					rtc4on_delay_min=EEPROM_READ(62);
					rtc4of_delay_hour=EEPROM_READ(63);
					rtc4of_delay_min=EEPROM_READ(64);

					rtc5on_delay_hour=EEPROM_READ(66);
					rtc5on_delay_min=EEPROM_READ(67);
					rtc5of_delay_hour=EEPROM_READ(68);
					rtc5of_delay_min=EEPROM_READ(69);

					rtc6on_delay_hour=EEPROM_READ(71);
					rtc6on_delay_min=EEPROM_READ(72);
					rtc6of_delay_hour=EEPROM_READ(73);
					rtc6of_delay_min=EEPROM_READ(74);

					rtc7on_delay_hour=EEPROM_READ(76);
					rtc7on_delay_min=EEPROM_READ(77);
					rtc7of_delay_hour=EEPROM_READ(78);
					rtc7of_delay_min=EEPROM_READ(79);

					rtc8on_delay_hour=EEPROM_READ(81);
					rtc8on_delay_min=EEPROM_READ(82);
					rtc8of_delay_hour=EEPROM_READ(83);
					rtc8of_delay_min=EEPROM_READ(84);

					rtc9on_delay_hour=EEPROM_READ(86);
					rtc9on_delay_min=EEPROM_READ(87);
					rtc9of_delay_hour=EEPROM_READ(88);
					rtc9of_delay_min=EEPROM_READ(89);

					rtc10on_delay_hour=EEPROM_READ(91);
					rtc10on_delay_min=EEPROM_READ(92);
					rtc10of_delay_hour=EEPROM_READ(93);
					rtc10of_delay_min=EEPROM_READ(94);

					user=EEPROM_READ(180);









		if(MODE_KEY==0||MODE_KEY==1)//motoron=0;cyclictimoff=1;rtcmode_enable=0;
		{
			cyclic_tim_of=EEPROM_READ(303);delay(20);
			rtcmode_enable=EEPROM_READ(310);delay(20);

			if(cyclic_tim_of==0)
			{
			cyclictimoff=EEPROM_READ(305);delay(20);
			cyclicon_min=EEPROM_READ(300);delay(20);
			cyclicof_min=EEPROM_READ(301);delay(20);
			cyclic_tim_on=EEPROM_READ(304);delay(20);
			motoron=EEPROM_READ(302);delay(20);
			cyclicon_sec=EEPROM_READ(308);delay(20);
			cyclicof_sec=EEPROM_READ(309);delay(20);
			}
			else if(cyclic_tim_of==1)// nchange cyclictimoff
			{
			cyclictimoff=EEPROM_READ(305);delay(20);
			cyclicon_min=EEPROM_READ(300);delay(20);
			cyclicof_min=EEPROM_READ(301);delay(20);
			cyclic_tim_on=EEPROM_READ(304);delay(20);
			motoron=EEPROM_READ(302);delay(20);
			cyclicon_sec=EEPROM_READ(308);delay(20);
			cyclicof_sec=EEPROM_READ(309);delay(20);
			}//nchange
			else if(rtcmode_enable==1){motoron=0;}
			else
			{
			cyclicon_min=cyclicof_min=cyclic_tim_of=cyclic_tim_on=0;
			cyclictimoff=1;
			}
		}
		else
		{
		cyclicon_min=cyclicof_min=cyclic_tim_of=cyclic_tim_on=0;
		motoron=EEPROM_READ(302);delay(20);cyclictimoff=1;
		}
		if(!MODE_KEY && cyclictimoff && !rtcmode_enable)
		{
			motoron=0;
			EEPROM_WRITE(302,motoron);
		}

	}
}
