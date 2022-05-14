
# 1.1 HIGH LEVEL TEST PLAN

| Test ID | Description | Input | Expected output | Actual Output | 
| --- | --- | --- | --- | --- | 
| 01 | Ignition On | 1st 2sec User Button Press | Ignition key status | Displayed Ignition key status  | 
| 02 | Viper On | 1st User Button Press | Viper Status-1Hz | Displayed Viper Status | 
| 03 | Viper On | 2nd User Button Press | Viper Status-4Hz | Displayed Viper Status | 
| 04 | Viper On | 3rd User Button Press | Viper Status-8Hz | Displayed Viper Status | 
| 05 | Ignition Off | 2nd 2sec User Button Press |  Ignition key status  | Displayed Ignition key status  | 

## LOW LEVEL REQUIREMENTS:

|RID|DESCRIPTION|STATUS|
|:--|:----------|:-----|
|LLR1|STM32 INTERFACING WITH PUSH BUTTONS|IMPLEMENTED|
|LLR2|PUSH BUTTONS INTERFACING WITH LEDS|IMPLEMENTED|
