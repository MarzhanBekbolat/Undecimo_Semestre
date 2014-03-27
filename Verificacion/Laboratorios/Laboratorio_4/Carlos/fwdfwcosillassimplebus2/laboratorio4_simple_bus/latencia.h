#include<systemc.h>
#include "simple_bus_types.h"
#include "simple_bus_master_blocking.h"
#include "simple_bus_master_non_blocking.h"
#include "simple_bus.h"

class latencia {
private:
double temp, temp_n, tiempo, tiempo_n;
double cont;
double cont_lat, cont_lat_n, latencia_total,latencia_total_n;


public:
;
double medir_latencia(double time, double cont_b){
tiempo = time/1000;
cont_lat=cont_lat+tiempo;
latencia_total=cont_lat/(cont_b);
sb_fprintf(stdout,"\n%g\tLATENCIA_blocking:\t%gciclo(s)\n", sc_time_stamp().to_double(), latencia_total);
return latencia_total;
}


double medir_latencia_n(double time_n, double cont_nb){
tiempo_n = time_n/1000;
cont_lat_n= cont_lat_n + tiempo_n;
latencia_total_n=cont_lat_n*2/(cont_nb);
sb_fprintf(stdout,"\n%g\tLATENCIA_non_blocking:\t%gciclo(s)\n", sc_time_stamp().to_double(), latencia_total_n);
return latencia_total_n;
}	  
};


