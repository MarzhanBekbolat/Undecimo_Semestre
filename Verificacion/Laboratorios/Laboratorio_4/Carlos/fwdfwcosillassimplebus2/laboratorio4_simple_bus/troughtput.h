#include<systemc.h>

class troughtput{
public:
double temp1,temp2, troughtput_total, temp1_n,temp2_n, troughtput_total_n;

double medir_troughtput(double tam, double time){
temp1 = (32 * tam)*1000/time;//sc_time_stamp().to_double();
temp2 += temp1;
troughtput_total=temp2;
sb_fprintf(stdout, "\n%g\tTROUGHTPUT:\t%g bits/ciclo\n\n", sc_time_stamp().to_double(), troughtput_total);
return troughtput_total;
}

double medir_troughtput_n(double time_n){
temp1_n = 32*1000/time_n;
temp2_n += temp1_n;
troughtput_total_n=temp2_n*10;//10;//*1000/sc_time_stamp().to_double();
sb_fprintf(stdout, "\n%g\tTROUGHTPUT:\t%g bits/ciclo\n\n", sc_time_stamp().to_double(), troughtput_total_n/10);
return troughtput_total_n;
}


};	


