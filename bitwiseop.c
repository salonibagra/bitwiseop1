#include<stdio.h>
#include<stdint.h>
/*function for w/r bit*/
    uint8_t returnbit(uint8_t rw)
     {
     	uint8_t getbyte;
     	if (rw==0)
     		getbyte= 0;
     	else
     		getbyte= 1;
     	return getbyte;
     }

  /*function for sector bits*/
    int select_sector(uint8_t n)
    {
  	  uint8_t sectorbits=0;
  	  int prevsector=2;
  	  if(n==-1)
  	  {
  		  if(prevsector>=0&&prevsector<=2)
  			  n=prevsector+1;
  		  else if(prevsector==3)
  			  n=0;
  	  }
  	  if(n>0=&&n<=3)
  		  sectorbits= (n&3);
  	  prevsector=n;
  	  /*
  	  else if(n==-1)
  	  {
  		  if(prevsector==0||prevsector==1||prevsector==2)
  			  n=n+1;
  		  else if(prevsector==3)
  			  n=0;
  	  }
  	  */
  	  return sectorbits;
    }

    /*function to obtain data bits*/
    uint8_t databit(uint8_t num)
    {	uint8_t n=0;

  		 n=(num&15);

  	  return n;
    }

    /*function to obtain parity bit*/
    uint8_t paritybit(int bytes)
    {
  	  uint8_t parity;
  	  int onecount,no;

  	  while(bytes)
  	  {
  		  no=bytes&1;
  		  if(no==1)
  			  onecount++;
  		  bytes=bytes>>1;
  	  }

  	  if((onecount%2)==0)
  		  parity=0;
  		  else
  			  parity=1;
  	  /*while(bytes)
  	  {
  		  parity=(parity^(bytes&1));
  		  bytes>>1;

  	  }*/
  	  return parity;

    }

    int main()
     {

      	int select=1,data=0,forparity;
      	uint8_t byte=00000000,value,parity,sector,recieved_bytes,ret;

      	if(select==0)
      		recieved_bytes=returnbit(0);

      	else
      		recieved_bytes=returnbit(1);
      	ret=recieved_bytes;
      	byte=(recieved_bytes|byte)<<2;


      	int n=1;
        sector=select_sector(n);
      	 byte=(byte|(sector&3))<<4;


      	if(recieved_bytes==1)
      		{
      		value=databit(data);
      		byte=(byte|(value&15))<<1;
      		}
      	else
      		{
      		byte=(byte|0)<<1;
      		}

      	/*forparity=byte;*/
      	parity=paritybit(forparity);
      	byte=byte|(parity&1);

      	}
