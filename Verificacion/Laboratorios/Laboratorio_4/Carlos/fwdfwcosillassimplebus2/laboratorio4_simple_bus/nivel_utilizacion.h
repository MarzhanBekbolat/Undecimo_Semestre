#include<systemc.h>

class nivel_utilizacion{

private: 
double ocup, deso, util;
public:
double ocupado(){
ocup++;
//sb_fprintf(stdout, "%g\tNivel de utilización:\t%g%\n", sc_time_stamp().to_double(), ocup);

return ocup;
}
void desocupado(){
deso+=1;
}

int utilizacion(double tiempo){
util = (100 * ocup/tiempo);
//sb_fprintf(stdout, "%g\tNivel de utilización:\t%g%\n", sc_time_stamp().to_double(), util);
return util;
}
};
