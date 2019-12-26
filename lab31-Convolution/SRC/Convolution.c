#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
#include "math.h" 

#define a  3 //x(n)�����г���
#define b  4 //h(n)�����г���
#define c  a+b-1  //y(n)�����г��� =a+b-1

//Uint16 Input[256];   
Uint16 x1[a]={3,2,1};   //�������1
Uint16 h1[b]={4,3,2,1}; //�������2
Uint16 y1[c];           //����������
/*=============================================================
    ���ܣ�ʵ����ɢ���Ծ��
�㷨ԭ����λ�����ͷ�ʵ�־��
�βΣ�xn��*x��ָ������鳤�ȣ���hn��*h��ָ������鳤�ȣ�Ϊ����
     �������������������鳤��
     *x��*hΪָ�����������ָ��
	 *yָ��������е�����
ע�⣺������г���Ϊxn+hn-1���������Ϊ�������� 0~(xn+hn-2)��
���⣬�ú���ʵ�ֵ��޷������͵ľ�����㣬���Ҫʵ�ָ����ͣ���Ҫ
���βε�Uint16 hn,Uint16 *x,Uint16 *h,Uint16 *y��Uint16���ݸ�ʽ
��Ϊfloat����double��
==============================================================*/
void LinearConvolution(Uint16 xn,Uint16 hn,Uint16 *x,Uint16 *h,Uint16 *y)  
{
   Uint16 i,j,k,l;
   Uint16 yn;   //�������y�ĳ���
   yn=xn+hn-1;
   for(i=0;i<yn;i++) y[i]=0;  //��������ʼ��
   k=yn-1;
   for(i=hn-1;i>0;i--)      //��*h��Ϊ������
    {
       l=k;
       for(j=xn-1;j>0;j--)  //����x[n]��1~(xn-1)��h[i]��һ���
	    {
           y[l]+=h[i]*x[j];
		   l--;
		}
	   y[l]+=x[0]*h[i];     
	   k--;
	}
	l=k;
   for(j=xn-1;j>0;j--)
	{
       y[l]+=h[0]*x[j];
	   l--;
    }
	y[l]+=x[0]*h[0];
}


void main(void)
{
  // Uint16 i;

   InitSysCtrl();

   InitXintf16Gpio();	//zq

   DINT;

   InitPieCtrl();


   IER = 0x0000;
   IFR = 0x0000;
   InitPieVectTable();
   LinearConvolution(a,b,x1,h1,y1);
   
 /*  for(i=0;i<256;i++) 
     { 
      Input[i]=200 * sin(2 * 3.14 * i / 255)+300+100 * cos(2 * 3.14 * 100* i / 255);
	   DELAY_US(10);
	 }*/

   

 while(1)
 {
     
 }

}


//===========================================================================
// No more.
//===========================================================================
