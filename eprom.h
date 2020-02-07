unsigned int eprom_read(unsigned char);
void eprom_write(unsigned char,unsigned int);
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

/*=============================== FUNCTION DEFINITIONS ======================*/
/************************************************************************************
*Function Name 	: read
*Description	: Function to read eeprom
*Parameters	    : None
*Return Type	: None
*************************************************************************************/
void read()
{
		/*EEPROM_READ(350) value to Power_On_Message_Flag*/
		Power_On_Message_Flag=EEPROM_READ(83);
		
		
		/*if condition to check eeprom_read(120) and (500) */
		if(eeprom_read(158)!='A' && eeprom_read(94)!='K'){
			
				/*EEPROM_WRITE(240) value to 241*/	
				EEPROM_WRITE(241,240);	

				/*EEPROM_WRITE(low_voltage_3ph) value to 0 */
				low_voltage_3ph=350;
				eprom_write(0,low_voltage_3ph);

				/*EEPROM_WRITE(high_voltage_3ph) value to 2 */
				high_voltage_3ph=500;
				eprom_write(2,high_voltage_3ph);

				/*EEPROM_WRITE(diff_3ph_volt) value to 4 */
				diff_3ph_volt=30;
				eprom_write(4,diff_3ph_volt);

				/*EEPROM_WRITE(dryrun_3ph_amps) value to 6 */
				dryrun_3ph_amps=100;
				eprom_write(6,dryrun_3ph_amps);

				/*EEPROM_WRITE(over_3ph_amps) value to 8 */
				over_3ph_amps=180;
				eprom_write(8,over_3ph_amps);

				/*EEPROM_WRITE(diff_amp) value to 77 */
				diff_amp=30;
				eprom_write(77,diff_amp);

				/*EEPROM_WRITE(ignor) value to 79 */
				ignor='N';
				eprom_write(79,ignor);
				
				user_ph_disable=EEPROM_READ(80);
				mode_key_state=EEPROM_READ(81);
				Thershould_voltage_level=175;
				
				/*EEPROM_WRITE(low_voltage_2ph) value to 10 */
				low_voltage_2ph=350;
				eprom_write(10,low_voltage_2ph);

				/*EEPROM_WRITE(high_voltage_2ph) value to 12 */
				high_voltage_2ph=500;
				eprom_write(12,high_voltage_2ph);

				/*EEPROM_WRITE(dryrun_2ph_amps) value to 14 */
				dryrun_2ph_amps=80;
				eprom_write(14,dryrun_2ph_amps);

				/*EEPROM_WRITE(over_2ph_amps) value to 16 */
				over_2ph_amps=200;
				eprom_write(16,over_2ph_amps);
				
				/*EEPROM_WRITE(dry_run_scantime) value to 18 */
				dry_run_scantime=3;
				eprom_write(18,dry_run_scantime);

				/*EEPROM_WRITE(over_load_scantime) value to 20 */
				over_load_scantime=3;
				eprom_write(19,over_load_scantime);

				/*EEPROM_WRITE(zero_amps_timer) value to 20 */
				zero_amps_timer=3;
				eprom_write(20,zero_amps_timer);

				/*EEPROM_WRITE(low_voltage_scan_time) value to 22 */
				low_voltage_scan_time=3;
				eprom_write(21,low_voltage_scan_time);

				/*EEPROM_WRITE(high_voltage_scan_time) value to 22 */
				high_voltage_scan_time=3;
				eprom_write(22,high_voltage_scan_time);

				/*EEPROM_WRITE(diff_voltage_scan_time) value to 22 */
				diff_voltage_scan_time=3;
				eprom_write(23,diff_voltage_scan_time);

				/*EEPROM_WRITE(star_delay_time) value to 24 */
				star_delay_time=3;
				eprom_write(24,star_delay_time);

				/*EEPROM_WRITE(starting_capacitor_delay) value to 26 */	
				starting_capacitor_delay=5;
				eprom_write(26,starting_capacitor_delay);

				/*EEPROM_WRITE(power_on_delay) value to 28 */
				power_on_delay=0;
				eprom_write(28,power_on_delay);

				/*EEPROM_WRITE(dry_run_restarttimer) value to 36 */
				dry_run_restarttimer=1;
				EEPROM_WRITE(25,dry_run_restarttimer);
				//eprom_write(25,dry_run_restarttimer);

				/*EEPROM_WRITE(manual_rst_count) value to 30 */
				manual_rst_count=1;
				temp_manual_rst_count=1;
				EEPROM_WRITE(30,manual_rst_count);
				
				cyclicon_delay_hour=0;
				EEPROM_WRITE(33,cyclicon_delay_hour);
				
				cyclicon_delay_min=0;
				EEPROM_WRITE(34,cyclicon_delay_min);
				
			
				cyclicof_delay_hour=0;
				EEPROM_WRITE(35,cyclicof_delay_hour);
				

				cyclicof_delay_min=0;
				EEPROM_WRITE(36,cyclicof_delay_min);
				
				
				/*for loop to write mob_number1,2,3,4 in 115,125,135,145*/
				for(loop=0;loop<=9;loop++)
				{
				mob_number2[loop]=0;delay(10);
				EEPROM_WRITE(115+loop,mob_number2[loop]);
				mob_number1[loop]=0;delay(10);
				EEPROM_WRITE(125+loop,mob_number1[loop]);
				mob_number3[loop]=0;delay(10);
				EEPROM_WRITE(135+loop,mob_number3[loop]);
				mob_number4[loop]=0;delay(10);
				EEPROM_WRITE(145+loop,mob_number4[loop]);
				}
					
					/*EEPROM_WRITE(mobileno1_enable_bit) value to 107 */
					mobileno1_enable_bit=0;
					EEPROM_WRITE(155,mobileno1_enable_bit);
					
					/*EEPROM_WRITE(mobileno2_enable_bit) value to 108 */
					mobileno2_enable_bit=0;
					EEPROM_WRITE(156,mobileno2_enable_bit);
					

					/*EEPROM_WRITE(mobileno3_enable_bit) value to 109 */
					mobileno3_enable_bit=0;
					EEPROM_WRITE(157,mobileno3_enable_bit);
					
					/*EEPROM_WRITE(mobileno4_enable_bit) value to 110 */
					mobileno4_enable_bit=0;
					EEPROM_WRITE(158,mobileno4_enable_bit);

		   			/*EEPROM_WRITE(rtc1on_delay_hour) value to 37 */
					rtc1on_delay_hour=0;
					EEPROM_WRITE(37,rtc1on_delay_hour);
					
					/*EEPROM_WRITE(rtc1on_delay_min) value to 38 */
					rtc1on_delay_min=0;
					EEPROM_WRITE(38,rtc1on_delay_min);

					/*EEPROM_WRITE(rtc1of_delay_hour) value to 39*/
					rtc1of_delay_hour=0;
					EEPROM_WRITE(39,rtc1of_delay_hour);

					/*EEPROM_WRITE(rtc1on_delay_min) value to 40*/
					rtc1of_delay_min=0;
					EEPROM_WRITE(40,rtc1of_delay_min);

					/*EEPROM_WRITE(rtc2on_delay_hour) value to 41 */
					rtc2on_delay_hour=0;
					EEPROM_WRITE(41,rtc2on_delay_hour);
		
					/*EEPROM_WRITE(rtc2on_delay_min) value to 42 */
					rtc2on_delay_min=0;
					EEPROM_WRITE(42,rtc2on_delay_min);


					/*EEPROM_WRITE(rtc2of_delay_hour) value to 43 */
					rtc2of_delay_hour=0;
					EEPROM_WRITE(43,rtc2of_delay_hour);

					/*EEPROM_WRITE(rtc2of_delay_min) value to 44 */
					rtc2of_delay_min=0;
					EEPROM_WRITE(44,rtc2of_delay_min);

					/*EEPROM_WRITE(rtc3on_delay_hour) value to 45 */
					rtc3on_delay_hour=0;
					EEPROM_WRITE(45,rtc3on_delay_hour);

					/*EEPROM_WRITE(rtc3on_delay_min) value to 46 */
					rtc3on_delay_min=0;
					EEPROM_WRITE(46,rtc3on_delay_min);

					/*EEPROM_WRITE(rtc3on_delay_hour) value to 47 */
					rtc3of_delay_hour=0;
					EEPROM_WRITE(47,rtc3of_delay_hour);

					/*EEPROM_WRITE(rtc3of_delay_min) value to 48*/
					rtc3of_delay_min=0;
					EEPROM_WRITE(48,rtc3of_delay_min);

					/*EEPROM_WRITE(rtc4on_delay_hour) value to 49*/
					rtc4on_delay_hour=0;
					EEPROM_WRITE(49,rtc4on_delay_hour);

					/*EEPROM_WRITE(rtc4on_delay_min) value to 50*/					
					rtc4on_delay_min=0;
					EEPROM_WRITE(50,rtc4on_delay_min);

					/*EEPROM_WRITE(rtc4of_delay_hour) value to 51*/
					rtc4of_delay_hour=0;
					EEPROM_WRITE(51,rtc4of_delay_hour);

					/*EEPROM_WRITE(rtc4of_delay_min) value to 52*/
					rtc4of_delay_min=0;
					EEPROM_WRITE(52,rtc4of_delay_min);

					/*EEPROM_WRITE(rtc5on_delay_hour) value to 53 */
					rtc5on_delay_hour=0;
					EEPROM_WRITE(53,rtc5on_delay_hour);

					/*EEPROM_WRITE(rtc5on_delay_min) value to 54 */
					rtc5on_delay_min=0;
					EEPROM_WRITE(54,rtc5on_delay_min);

					/*EEPROM_WRITE(rtc5of_delay_hour) value to 55*/					
					rtc5of_delay_hour=0;
					EEPROM_WRITE(55,rtc5of_delay_hour);
					
					/*EEPROM_WRITE(rtc5of_delay_min) value to 56*/
					rtc5of_delay_min=0;
					EEPROM_WRITE(56,rtc5of_delay_min);

					/*EEPROM_WRITE(rtc6on_delay_hour) value to 57*/
					rtc6on_delay_hour=0;
					EEPROM_WRITE(57,rtc6on_delay_hour);
			
					/*EEPROM_WRITE(rtc6on_delay_min) value to 58*/
					rtc6on_delay_min=0;
					EEPROM_WRITE(58,rtc6on_delay_min);

					/*EEPROM_WRITE(rtc6of_delay_hour) value to 59*/
					rtc6of_delay_hour=0;
					EEPROM_WRITE(59,rtc6of_delay_hour);

					/*EEPROM_WRITE(rtc6of_delay_min) value to 60*/
					rtc6of_delay_min=0;
					EEPROM_WRITE(60,rtc6of_delay_min);

					/*EEPROM_WRITE(rtc6on_delay_hour) value to 61*/
					rtc7on_delay_hour=0;
					EEPROM_WRITE(61,rtc7on_delay_hour);

					/*EEPROM_WRITE(rtc7of_delay_min) value to 62*/
					rtc7on_delay_min=0;
					EEPROM_WRITE(62,rtc7of_delay_min);

					/*EEPROM_WRITE(rtc7of_delay_hour) value to 63*/
					rtc7of_delay_hour=0;
					EEPROM_WRITE(63,rtc7of_delay_hour);

					/*EEPROM_WRITE(rtc7of_delay_min) value to 64*/
					rtc7of_delay_min=0;
					EEPROM_WRITE(64,rtc7of_delay_min);

					/*EEPROM_WRITE(rtc7on_delay_hour) value to 65*/
					rtc8on_delay_hour=0;
					EEPROM_WRITE(65,rtc8on_delay_hour);

					/*EEPROM_WRITE(rtc8on_delay_min) value to 66*/
					rtc8on_delay_min=0;
					EEPROM_WRITE(66,rtc8on_delay_min);
		
					/*EEPROM_WRITE(rtc8of_delay_hour) value to 67*/
					rtc8of_delay_hour=0;
					EEPROM_WRITE(67,rtc8of_delay_hour);

					/*EEPROM_WRITE(rtc8of_delay_min) value to 68*/
					rtc8of_delay_min=0;
					EEPROM_WRITE(68,rtc8of_delay_min);

					/*EEPROM_WRITE(rtc9on_delay_hour) value to 69*/
					rtc9on_delay_hour=0;
					EEPROM_WRITE(69,rtc9on_delay_hour);

					/*EEPROM_WRITE(rtc9on_delay_min) value to 70*/
					rtc9on_delay_min=0;
					EEPROM_WRITE(70,rtc9on_delay_min);

					/*EEPROM_WRITE(rtc9of_delay_hour) value to 71*/
					rtc9of_delay_hour=0;
					EEPROM_WRITE(71,rtc9of_delay_hour);

					/*EEPROM_WRITE(rtc9of_delay_min) value to 72*/
					rtc9of_delay_min=0;
					EEPROM_WRITE(72,rtc9of_delay_min);

					/*EEPROM_WRITE(rtc10of_delay_min) value to 73*/
					rtc10on_delay_hour=0;
					EEPROM_WRITE(73,rtc10on_delay_hour);

					/*EEPROM_WRITE(rtc10of_delay_min) value to 74*/
					rtc10on_delay_min=0;
					EEPROM_WRITE(74,rtc10on_delay_min);

					/*EEPROM_WRITE(rtc7of_delay_min) value to 75*/
					rtc10of_delay_hour=0;
					EEPROM_WRITE(75,rtc10of_delay_hour);

					/*EEPROM_WRITE(rtc7of_delay_min) value to 76*/
					rtc10of_delay_min=0;
					EEPROM_WRITE(76,rtc10of_delay_min);

					cyclic_tim_of=1;
					EEPROM_WRITE(84,cyclic_tim_of);

    				cyclic_tim_on=0;
					EEPROM_WRITE(89,cyclic_tim_of);
				
					cyclicon_min=0;
					EEPROM_WRITE(87,cyclic_tim_of);
			
					cyclictimoff=1;
					EEPROM_WRITE(86,cyclic_tim_of);

					rtcmode_enable=0;					
					EEPROM_WRITE(85,rtcmode_enable);

					user=0;
					EEPROM_WRITE(82,user=0);
					
				
			}	
		
		else 
			{

				zero_amps_timer=dry_run_scantime;//eprom_read(18);
				high_voltage_scan_time=low_voltage_scan_time;
				diff_voltage_scan_time=low_voltage_scan_time;
				
				/*for loop to read  mob_number1,2,3,4 from 110,121,131,141*/
				for(loop=0;loop<=9;loop++)
				{
				mob_number2[loop]=eeprom_read(115+loop);delay(10);
				mob_number1[loop]=eeprom_read(125+loop);delay(10);
				mob_number3[loop]=eeprom_read(135+loop);delay(10);
				mob_number4[loop]=eeprom_read(145+loop);delay(10);
				}
					/*eeprom_read(155) for mobileno1_enable_bit*/
					mobileno1_enable_bit=eeprom_read(155);

					/*eeprom_read(156) for mobileno2_enable_bit*/
					mobileno2_enable_bit=eeprom_read(156);

					/*eeprom_read(157) for mobileno3_enable_bit*/
					mobileno3_enable_bit=eeprom_read(157);

					/*eeprom_read(158) for mobileno4_enable_bit*/
					mobileno4_enable_bit=eeprom_read(158);
					
					/*EEPROM_READ(37) for rtc1on_delay_hour*/		   		
					rtc1on_delay_hour=EEPROM_READ(37);

					/*EEPROM_READ(38) for rtc1on_delay_min*/		   
					rtc1on_delay_min=EEPROM_READ(38);

					/*EEPROM_READ(39) for rtc1on_delay_hour*/		   
					rtc1of_delay_hour=EEPROM_READ(39);

					/*EEPROM_READ(40) for rtc1on_delay_min*/		   
					rtc1of_delay_min=EEPROM_READ(40);
					
					/*EEPROM_READ(41) for rtc2on_delay_hour*/
					rtc2on_delay_hour=EEPROM_READ(41);

					/*EEPROM_READ(42) for rtc2on_delay_min*/
					rtc2on_delay_min=EEPROM_READ(42);

					/*EEPROM_READ(43) for rtc2on_delay_hour*/
					rtc2of_delay_hour=EEPROM_READ(43)
;					
					/*EEPROM_READ(44) for rtc2on_delay_min*/
					rtc2of_delay_min=EEPROM_READ(44);

					/*EEPROM_READ(45) for rtc3on_delay_hour*/
					rtc3on_delay_hour=EEPROM_READ(45);

					/*EEPROM_READ(46) for rtc3on_delay_min*/
					rtc3on_delay_min=EEPROM_READ(46);

					/*EEPROM_READ(47) for rtc3on_delay_hour*/
					rtc3of_delay_hour=EEPROM_READ(47);

					/*EEPROM_READ(48) for rtc3on_delay_min*/
					rtc3of_delay_min=EEPROM_READ(48);

					/*EEPROM_READ(49) for rtc4on_delay_hour*/
					rtc4on_delay_hour=EEPROM_READ(49);

					/*EEPROM_READ(50) for rtc4on_delay_min*/
					rtc4on_delay_min=EEPROM_READ(50);

					/*EEPROM_READ(51) for rtc4on_delay_hour*/
					rtc4of_delay_hour=EEPROM_READ(51);

					/*EEPROM_READ(52) for rtc4on_delay_min*/
					rtc4of_delay_min=EEPROM_READ(52);

					/*EEPROM_READ(53) for rtc5on_delay_hour*/
					rtc5on_delay_hour=EEPROM_READ(53);

					/*EEPROM_READ(54) for rtc5on_delay_min*/
					rtc5on_delay_min=EEPROM_READ(54);

					/*EEPROM_READ(55) for rtc5on_delay_hour*/
					rtc5of_delay_hour=EEPROM_READ(55);

					/*EEPROM_READ(56) for rtc5on_delay_min*/
					rtc5of_delay_min=EEPROM_READ(56);
					
					/*EEPROM_READ(57) for rtc6on_delay_hour*/
					rtc6on_delay_hour=EEPROM_READ(57);

					/*EEPROM_READ(58) for rtc6on_delay_min*/
					rtc6on_delay_min=EEPROM_READ(58);

					/*EEPROM_READ(59) for rtc6on_delay_hour*/
					rtc6of_delay_hour=EEPROM_READ(59);

					/*EEPROM_READ(60) for rtc6on_delay_min*/
					rtc6of_delay_min=EEPROM_READ(60);

					/*EEPROM_READ(61) for rtc7on_delay_hour*/
					rtc7on_delay_hour=EEPROM_READ(61);

					/*EEPROM_READ(62) for rtc7on_delay_min*/
					rtc7on_delay_min=EEPROM_READ(62);

					/*EEPROM_READ(63) for rtc7on_delay_hour*/
					rtc7of_delay_hour=EEPROM_READ(63);

					/*EEPROM_READ(64) for rtc7on_delay_min*/
					rtc7of_delay_min=EEPROM_READ(64);

					/*EEPROM_READ(65) for rtc8on_delay_hour*/
					rtc8on_delay_hour=EEPROM_READ(65);

					/*EEPROM_READ(66) for rtc8on_delay_min*/
					rtc8on_delay_min=EEPROM_READ(66);

					/*EEPROM_READ(67) for rtc8on_delay_min*/
					rtc8of_delay_hour=EEPROM_READ(67);

					/*EEPROM_READ(68) for rtc8on_delay_min*/
					rtc8of_delay_min=EEPROM_READ(68);

					/*EEPROM_READ(69) for rtc8on_delay_hour*/
					rtc9on_delay_hour=EEPROM_READ(69);

					/*EEPROM_READ(70) for rtc9on_delay_min*/
					rtc9on_delay_min=EEPROM_READ(70);

					/*EEPROM_READ(72) for rtc9on_delay_hour*/
					rtc9of_delay_hour=EEPROM_READ(71);

					/*EEPROM_READ(72) for rtc9on_delay_min*/
					rtc9of_delay_min=EEPROM_READ(72);
					
					/*EEPROM_READ(73) for rtc10on_delay_hour*/
					rtc10on_delay_hour=EEPROM_READ(73);

					/*EEPROM_READ(74) for rtc10on_delay_min*/
					rtc10on_delay_min=EEPROM_READ(74);

					/*EEPROM_READ(75) for rtc10on_delay_hour*/
					rtc10of_delay_hour=EEPROM_READ(75);

					/*EEPROM_READ(76) for rtc10on_delay_min*/
					rtc10of_delay_min=EEPROM_READ(76);
				
					/*EEPROM_READ(82) for user*/
					user=EEPROM_READ(82);
		
		/*if condition to check state of mode*/
		if(MODE_KEY==0||MODE_KEY==1)//motoron=0;cyclictimoff=1;rtcmode_enable=0;
		{
			/*EEPROM_READ(84) for cyclic_tim_of*/
			cyclic_tim_of=EEPROM_READ(84);delay(20);
			
			/*EEPROM_READ(85) for rtcmode_enable*/
			rtcmode_enable=EEPROM_READ(85);delay(20);
			
			if(cyclic_tim_of==0)
			{
			/*EEPROM_READ(86) for cyclictimoff*/
			cyclictimoff=EEPROM_READ(86);delay(20);

			/*EEPROM_READ(87) for cyclicon_min*/
			cyclicon_min=EEPROM_READ(87);delay(20);
			
			/*EEPROM_READ(88) for cyclicof_min*/
			cyclicof_min=EEPROM_READ(88);delay(20);

			/*EEPROM_READ(89) for cyclic_tim_on*/
			cyclic_tim_on=EEPROM_READ(89);delay(20);

			/*EEPROM_READ(90) for motoron*/
			motoron=EEPROM_READ(90);delay(20);

			/*EEPROM_READ(91) for cyclicon_sec*/
			cyclicon_sec=EEPROM_READ(91);delay(20);
			
			/*EEPROM_READ(92) for cyclicof_sec*/
			cyclicof_sec=EEPROM_READ(92);delay(20);
			}
			/*else if condition to check cyclic_tim_of state*/
			else if(cyclic_tim_of==1)// nchange cyclictimoff
			{
			/*EEPROM_READ(86) for cyclictimoff*/
			cyclictimoff=EEPROM_READ(86);delay(20);

			/*EEPROM_READ(87) for cyclicon_min*/
			cyclicon_min=EEPROM_READ(87);delay(20);

			/*EEPROM_READ(88) for cyclicof_min*/
			cyclicof_min=EEPROM_READ(88);delay(20);

			/*EEPROM_READ(89) for cyclic_tim_on*/
			cyclic_tim_on=EEPROM_READ(89);delay(20);

			/*EEPROM_READ(90) for motoron*/
			motoron=EEPROM_READ(90);delay(20);
	
			/*EEPROM_READ(91) for cyclicon_sec*/
			cyclicon_sec=EEPROM_READ(91);delay(20);

			/*EEPROM_READ(92) for cyclicof_sec*/
			cyclicof_sec=EEPROM_READ(92);delay(20);
			}

			/*else if condition to check rtcmode_enable state*/
			else if(rtcmode_enable==1)
			{motoron=0;}
			else 
			{
			cyclicon_min=cyclicof_min=cyclic_tim_of=cyclic_tim_on=0;
			cyclictimoff=1;
			}
		}
		else 
		{
		cyclicon_min=cyclicof_min=cyclic_tim_of=cyclic_tim_on=0;
		motoron=EEPROM_READ(90);delay(20);cyclictimoff=1;
		}
		
		/*if condition to check state of MODE_KEY,cyclictimoff,rtcmode_enable*/
		if(!MODE_KEY && cyclictimoff && !rtcmode_enable){
			motoron=0;
			EEPROM_WRITE(90,motoron);
		}
		
	}
}/* End of function void read()
*************************************************************************************/

/*mobileno1_enable_bit=0;
					mobileno2_enable_bit=0;
					mobileno3_enable_bit=0;
					mobileno4_enable_bit=0;
					
		   		
					rtc1on_delay_hour=0;
					rtc1on_delay_min=0;
					rtc1of_delay_hour=0;
					rtc1of_delay_min=0;
					
					rtc2on_delay_hour=0;
					rtc2on_delay_min=0;
					rtc2of_delay_hour=0;
					rtc2of_delay_min=0;

					rtc3on_delay_hour=0;
					rtc3on_delay_min=0;
					rtc3of_delay_hour=0;
					rtc3of_delay_min=0;

					rtc4on_delay_hour=0;
					rtc4on_delay_min=0;
					rtc4of_delay_hour=0;
					rtc4of_delay_min=0;

					rtc5on_delay_hour=0;
					rtc5on_delay_min=0;
					rtc5of_delay_hour=0;
					rtc5of_delay_min=0;

					rtc6on_delay_hour=0;
					rtc6on_delay_min=0;
					rtc6of_delay_hour=0;
					rtc6of_delay_min=0;

					rtc7on_delay_hour=0;
					rtc7on_delay_min=0;
					rtc7of_delay_hour=0;
					rtc7of_delay_min=0;

					rtc8on_delay_hour=0;
					rtc8on_delay_min=0;
					rtc8of_delay_hour=0;
					rtc8of_delay_min=0;

					rtc9on_delay_hour=0;
					rtc9on_delay_min=0;
					rtc9of_delay_hour=0;
					rtc9of_delay_min=0;

					rtc10on_delay_hour=0;
					rtc10on_delay_min=0;
					rtc10of_delay_hour=0;
					rtc10of_delay_min=0;

					cyclic_tim_of=1;
    				cyclic_tim_on=0;
					cyclicon_min=0;
					cyclictimoff=1;rtcmode_enable=0;
					user=0;*/
/*eprom_read
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
				
				diff_amp=eprom_read(170);
				ignor=eprom_read(172);
				user_ph_disable=EEPROM_READ(174);
				mode_key_state=EEPROM_READ(175);	

				
				
				/*dry_run_scantime=eprom_read(18);
				over_load_scantime=eprom_read(20);
				zero_amps_timer=eprom_read(22);
				low_voltage_scan_time=eprom_read(24);
				high_voltage_scan_time=eprom_read(26);
				diff_voltage_scan_time=eprom_read(28);
				star_delay_time=eprom_read(30);
				starting_capacitor_delay=eprom_read(32);
				power_on_delay=eprom_read(34);
				dry_run_restarttimer=eprom_read(36);
				*/
	//	for(loop=1;loop<=40;loop++)
				//	{
					//a4[]=eeprom_read(36+k);
				//	}
				/*sethour=eeprom_read(78);
				setmin=eeprom_read(79);
				setsec=eeprom_read(80);
				setdate=eeprom_read(81);
				setmonth=eeprom_read(82);
				setyear=eeprom_read(83)|(eeprom_read(84)<<8);
				//if(MODE_KEY==1)motoron=0;
		//else motoron=EEPROM_READ(302);
		
		///////////////////////*/