  /** 
  *		Autor: Mário Antônio
  *		Data:  01/06/2015
  
  *		Sistema composto de:
  *		#Placa Arduino Uno;
  *		#Motor servo Tower Pro MG90S:  
  *		sinal(laranja) = pino digital 4, 
  *		positivo(marrom) = GND analogico, 
  *		negativo (vermelho) = 5v analogico
  *		#Módulo Bluetooth HC-05
  *
  *		Sistema recebe instruções de operações via bluetooth atraves de um aplicativo android "Bluetooth spp tools pro", 
  *		software para as ferramentas de comunicação cliente Bluetooth (slave mode)
  */
  
  
  #include <Servo.h>
  Servo motor;
 
  void setup() {
 
    motor.attach(4);  //pino de sinal no 4
    motor.write(14);  // valores para o Tower Pro MG90S = 14 ~ 179
    Serial.begin(9600);
    
    }

  void loop() {
       
        if (Serial.available())
        {
        char caracterSer = Serial.read();
        
              if(caracterSer == 'o')
              {
                abrirPortao(motor.read());
                Serial.println(motor.read());
              }
              if(caracterSer == 'c')
              {
                fecharPortao(motor.read());
                Serial.println(motor.read());
              }
        }
  }
      /** MODULO PARA CONTROLE DA ABERTURA DO PORTÃO*/
      
          int abrirPortao(int posicao){
       	  int i;
      
       	 // laço que faz motor do portão realizar um giro horario, abrindo
      
              for(i=posicao;i<180;i++) {
                 motor.write(i); 
                 delay(10); // atraso para evitar movimento rapido
              }
                 delay(1000);
        return posicao;
      }
      /** MODULO PARA CONTROLE DO FECHAMENTO DO PORTÃO*/
          int fecharPortao(int posicao){
          int i;
             
      	 // laço que faz motor do portão realizar um giro antihorario, fechando
      
              for(i=posicao;i>13;i--) {
       	      	motor.write(i); 
            	delay(10);  // atraso para evitar movimento rapido
              }
             	delay(1000);
        return posicao;
      }
