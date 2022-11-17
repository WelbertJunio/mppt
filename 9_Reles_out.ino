void Reles_out(){
    if (digitalRead(relayoffPIN) == LOW ){
    
    digitalWrite(relay1PIN, LOW); // Turn oN relay.
    delay(10);
    digitalWrite(relayPIN, LOW); // Turn off relay. 
    lcd.setCursor(0, 3);  
    lcd.print("Inversor OFF"); 
    
    }else{

  if (voltageOutput <= voltageBatteryMin && digitalRead(relay1PIN) == HIGH)
   {
    chargingPause = 0;
    delay(5000);
    
    if (voltageOutput <= voltageBatteryMin)
   {
    digitalWrite(relay1PIN, LOW); // Turn oN relay.
    delay(150);
    digitalWrite(relayPIN, LOW); // Turn off relay. 
    lcd.setCursor(0, 3); 
    lcd.print("Inversor OFF ");
    chargingPause = 1;
    }
   }  
   else if ((voltageOutput > voltageBatteryMin)  && digitalRead(relay1PIN) == HIGH)
   {
   lcd.setCursor(0, 3); 
   lcd.print("Inversor ON ");
          
   }
   else if ((voltageOutput > voltageBatteryON)  && digitalRead(relay1PIN) == LOW)
   {
    chargingPause = 1;
    digitalWrite(relayPIN, HIGH); // Turn oN relay.
    delay(8000);
    digitalWrite(relay1PIN, HIGH); // Turn off relay. 
    lcd.setCursor(0, 3); 
   lcd.print("Inversor ON ");
   chargingPause = 0;
   
    }
  }
}
