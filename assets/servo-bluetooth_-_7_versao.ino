    
    /*
    
    AUTHOR: Hazim Bitar (techbitar)
    DATE: Aug 29, 2013
    LICENSE: Public domain (use at your own risk)
    CONTACT: techbitar at gmail dot com (techbitar.com)
    
    */
    
    
    #include <SoftwareSerial.h>
    #include <Servo.h>
    Servo motor;
    SoftwareSerial BTSerial(10, 11); // RX | TX
    short int a,f;
    
    
    void setup()
    {
      pinMode(13, OUTPUT);
      pinMode(9, OUTPUT);  // pino para ser usando na configuração do modulo HC-05 em comando AT 
      motor.attach(4);  //pino de sinal do servo no
      //  digitalWrite(9, HIGH);
      //  Serial.begin(9600);
      BTSerial.begin(38400);  //velocidade padrão para comando AT no HC-05
      motor.write(14);  // valores para o Tower Pro MG90S = 14 ~ 179
      
    
    }
    
    void loop()
    {
    
    
    
      if (BTSerial.available()) {
     
        char comand = (BTSerial.read());
        short int posicao = motor.read();
    
        
        if (comand == 'a' && posicao != 179) {
          a++;
          abrirPortao(motor.read());
          BTSerial.print("Abrindo portão pela ");
          BTSerial.print(a);
          BTSerial.println("ª vez");
          BTSerial.flush();
          piscar();
    
        }
        if (comand == 'f' && posicao != 14) {
          f++;
          fecharPortao(motor.read());
          BTSerial.print("fechando portão pela ");
          BTSerial.print(f);
          BTSerial.println("ª vez");
          BTSerial.flush();
          piscar();
        }
      }
    }
    
    
    
    /** MODULO PARA CONTROLE DA ABERTURA DO PORTÃO*/
    
    int abrirPortao(int posicao) {
      int i;
    
      // laço que faz motor do portão realizar um giro horario, abrindo
    
      for (i = posicao; i < 180; i++) {
        motor.write(i);
        delay(10); // atraso para evitar movimento rapido
      }
      delay(1000);
      return posicao;
    }
    /** MODULO PARA CONTROLE DO FECHAMENTO DO PORTÃO*/
    int fecharPortao(int posicao) {
      int i;
    
      // laço que faz motor do portão realizar um giro antihorario, fechando
    
      for (i = posicao; i > 13; i--) {
        motor.write(i);
        delay(10);  // atraso para evitar movimento rapido
      }
      delay(1000);
      return posicao;
    }
    
    /** MÓDULO PISCAR DO LED DO ARDUINO*/
    void piscar() {
      int cont = 0;
      while (cont <= 10) {
        pinMode(13, HIGH);
        delay(70);
        pinMode(13, LOW);
        delay(70);
        cont++;
      }
    }
    

