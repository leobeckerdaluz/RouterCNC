#include "readString.h"

int bufferPosition[7];
int i=0, state = 0;
int aux, first,second;
String buffer = " ";

extern struct values valuesData;

uint8_t findPosition()
{
    if (Serial.available()) 
    {
        buffer = Serial.readString();
        
        Serial.print("Eu recebi: ");
        Serial.println(buffer);

        Serial.println(sizeof(buffer));
        first = buffer.indexOf("$");
        second = buffer.indexOf("#");
        Serial.println("Primeiro ");
        Serial.println(first);
        Serial.println("Segundo ");
        Serial.println(second);

        if(first < 0 || second < 0){
            Serial.println("Formato String errado.");
        }
        else{
            Serial.println("String Correta ");
            state = STR_CORRECT;
        }

        while ( state <=7)
        {
            switch (state)
            {
                case STR_CORRECT:
                {
                    if(buffer.indexOf("S=") > 0 )
                    {   
                        bufferPosition[0] = buffer.indexOf("S=");
                        // Serial.println("S");
                        //Serial.println(buffer.indexOf("S="));
                        // value = buffer.substring(buffer.indexOf("S=")+2, second);
                        // Serial.println(value);
                    }else{
                    bufferPosition[0] =-1;

                    }
                    state = STEP_TWO;
                    break;

                }
                Serial.println("Stepp two");

                case STEP_TWO:
                {

                
                    if(buffer.indexOf("M3") > 0)
                    {
                        Serial.println("M3 YES");
                        bufferPosition[1] = buffer.indexOf("M3");
                    }else{
                    bufferPosition[1] =-1;
                    
                    }
                    state = STEP_THREE;
                    break;
                }

                case STEP_THREE:
                {
                    if(buffer.indexOf("M4") > 0)
                    {
                        bufferPosition[2] = buffer.indexOf("M4");
                    }else{
                    bufferPosition[2] =-1;
                    
                    } 
                    state = STEP_FOUR;
                    break;
                }

                case STEP_FOUR:
                {
                    if(buffer.indexOf("F=") > 0)
                    {
                        bufferPosition[3] = buffer.indexOf("F=");
                    }else{
                    bufferPosition[3] =-1;
                    
                    } 
                    state = STEP_FIVE;
                    break;
                }

                case STEP_FIVE:
                {
                    if(buffer.indexOf("X=") > 0)
                    {
                        bufferPosition[4] = buffer.indexOf("X=");
                    }else{
                    bufferPosition[4] =-1;
                    
                    } 
                    state = STEP_SIX;
                    break;
                }

                case STEP_SIX:
                {
                    if(buffer.indexOf("Y=") > 0)
                    {
                        bufferPosition[5] = buffer.indexOf("Y=");
                    }else{
                    bufferPosition[5] =-1;
                    
                    } 
                    state = STEP_SEVEN;
                    break;
                }

                case STEP_SEVEN:
                {
                    if(buffer.indexOf("Z=") > 0)
                    {
                        bufferPosition[6] = buffer.indexOf("Z=");
                    }else{
                    bufferPosition[6] =-1;
                    
                    
                    } 
                    state =8;
                    break;
                }


            }
        }

        for(i =0; i < 7;i++)
            Serial.println(bufferPosition[i]);

        return 1;
    }

    return 0;
}

String findNext(int id)
{
      int aux;
      aux = bufferPosition[id];
      int aux2 = 100 - bufferPosition[id];
      int posi, last;

      posi = last = 0;

      for(i =0; i < 7;i++)
      {
        if(aux < bufferPosition[i])
        {
           last =1;
          if( (bufferPosition[i] - bufferPosition[id]) < aux2)
          {
            aux2 = bufferPosition[i] - bufferPosition[id];
            //aux = bufferPosition[i];
            posi = i;
            
          }

           
        }
      }

      
     
      if(id==1 || id == 2)
      {
         //Serial.println(buffer.substring(bufferPosition[id],  bufferPosition[posi]));
         

         if(last==0)
         {
             return buffer.substring(bufferPosition[id],  second);
         }else{
             return buffer.substring(bufferPosition[id],  bufferPosition[posi]);
         }

         
      }else{

          if(last == 0)
          {
           
            //Serial.println(buffer.substring(bufferPosition[id]+2,  second));
            return buffer.substring(bufferPosition[id]+2,  second);

          }else{
             //Serial.println(buffer.substring(bufferPosition[id]+2,  bufferPosition[posi]));
             return buffer.substring(bufferPosition[id]+2,  bufferPosition[posi]);
          }
           


           

      }
       
  
}

void getData()
{
    state = STR_CORRECT;

    while(state != (STEP_SEVEN +1))
    {
        switch (state)
        {
            case STR_CORRECT:
            {  
                if(bufferPosition[0] > 0)
                {
                    Serial.println("Valor do S");
                    Serial.println(findNext(0));
                    valuesData.S_Value = findNext(0).toInt();
                    
                    
                }else{
                    valuesData.S_Value = -1;
                }
                    
                state = STEP_TWO;
                break;

            }
            Serial.println("Stepp two");

            case STEP_TWO:
            {

                if(bufferPosition[1] > 0)
                {
                    Serial.println("Valor do M");
                    Serial.println(findNext(1));
                    valuesData.M3_Value = findNext(1);
                }else{
                    valuesData.M3_Value = "Null";
                }

                state = STEP_THREE;
                break;
            }

            case STEP_THREE:
            {
                if(bufferPosition[2] > 0)
                {
                    Serial.println("Valor do M");
                    Serial.println(findNext(2));
                    valuesData.M4_Value = findNext(2);
                }else{
                    valuesData.M4_Value = "Null";
                }
                state = STEP_FOUR;
                break;
            }

            case STEP_FOUR:
            {
                if(bufferPosition[3] > 0)
                {
                    Serial.println("Valor do F");
                    Serial.println(findNext(3));
                    valuesData.F_Value = findNext(3);
                }else{
                    valuesData.F_Value = "Null";
                }
                state = STEP_FIVE;
                break;
            }

            case STEP_FIVE:
            {
                if(bufferPosition[4] > 0)
                {
                    Serial.println("Valor do X");
                    Serial.println(findNext(4));
                    valuesData.X_Value = findNext(4).toInt();
                }else{
                    valuesData.X_Value = 0;
                }

                state = STEP_SIX;
                break;
            }

            case STEP_SIX:
            {
                if(bufferPosition[5] > 0)
                {
                    Serial.println("Valor do Y");
                    Serial.println(findNext(5));
                    valuesData.Y_Value = findNext(5).toInt();
                }else{
                    valuesData.Y_Value = 0;
                }

                state = STEP_SEVEN;
                break;
            }

            case STEP_SEVEN:
            {
                if(bufferPosition[6] > 0)
                {
                    Serial.println("Valor do Z");
                    valuesData.Z_Value = findNext(6).toInt();
                    Serial.println(valuesData.Z_Value);
                }else{
                    valuesData.Z_Value = 0;
                }
                state =8;
                break;
            }
        }
    }
}