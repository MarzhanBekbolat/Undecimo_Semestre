
% Parcial.m
% 
% A set of operations to simulate a 12 pulse rectifier
%
% Copyright 2013 Sergio Torres <sdtorresl@unal.edu.co>
% 
% This program is free software; you can redistribute it and/or modify
% it under the terms of the GNU General Public License as published by
% the Free Software Foundation; either version 2 of the License, or
% (at your option) any later version.
% 
% This program is distributed in the hope that it will be useful,
% but WITHOUT ANY WARRANTY; without even the implied warranty of
% MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
% GNU General Public License for more details.
% 
% You should have received a copy of the GNU General Public License
% along with this program; if not, write to the Free Software
% Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
% MA 02110-1301, USA.
%  

clear all;

points = 3600; % Number of  points for plot
omegat=[0: 2*pi/points: 2*pi]; %Angle
Vp = 170; % Peak Voltage
R = 1; % Resistance on the output
Io = 1;

%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Serial Circuit Analysis %
%%%%%%%%%%%%%%%%%%%%%%%%%%%

Va1_s = Vp*sin(omegat);
Vb1_s = Vp*sin(omegat + (2*pi/3));
Vc1_s = Vp*sin(omegat - (2*pi/3));

Va2_s = Vp*sin(omegat + (pi/6));
Vb2_s = Vp*sin(omegat + (2*pi/3) + (pi/6));
Vc2_s = Vp*sin(omegat - (2*pi/3) + (pi/6));

%figure;
%hold on,
%grid;
%plot(omegat, Va1_p, ";Va1_p; m");
%plot(omegat, Vb1_p, ";Vb1_p; r");
%plot(omegat, Vc1_p, ";Vc1_p; g");
%plot(omegat, Va2_p, ";Va2_p; k");
%plot(omegat, Vb2_p, ";Vb2_p; b");
%plot(omegat, Vc2_p, ";Vc2_p; c");
%xlabel('Angulo [rad]');
%ylabel('Tensión [V]');
%%axis([0, 2*pi+1, -5, 5], "normal");
%
%print tensiones_in_2.png;


Vrec1_s = max(max(Va1_s, Vb1_s),Vc1_s) - min(min(Va1_s, Vb1_s),Vc1_s);
Vrec2_s = max(max(Va2_s, Vb2_s),Vc2_s) - min(min(Va2_s, Vb2_s),Vc2_s);

Vrec_s = Vrec1_s+Vrec2_s;



% Initialize of variables
Ia1_s = zeros(size(omegat));
Ib1_s = zeros(size(omegat));
Ic1_s = zeros(size(omegat));
Ia2_s = zeros(size(omegat));
Ib2_s = zeros(size(omegat));
Ic2_s = zeros(size(omegat));

for j= [1:1:points+1]
	if ( Va1_s(:,j)> Vb1_s(:,j) && Va1_s(:,j)>Vc1_s(:,j) )
		Ia1_s(:,j)=Io;
	endif
	if ( Vb1_s(:,j)> Va1_s(:,j) && Vb1_s(:,j)>Vc1_s(:,j) )
		Ib1_s(:,j)=Io;
	endif	
	if ( Vc1_s(:,j)> Vb1_s(:,j) && Vc1_s(:,j)>Va1_s(:,j) )
		Ic1_s(:,j)=Io;
	endif
	if ( Va1_s(:,j)< Vb1_s(:,j) && Va1_s(:,j)<Vc1_s(:,j) )
		Ia1_s(:,j)=-Io;
	endif
	if ( Vb1_s(:,j)< Va1_s(:,j) && Vb1_s(:,j)<Vc1_s(:,j) )
		Ib1_s(:,j)=-Io;
	endif
	if ( Vc1_s(:,j)< Vb1_s(:,j) && Vc1_s(:,j)<Va1_s(:,j) )
		Ic1_s(:,j)=-Io;
	endif
	if ( Va2_s(:,j)> Vb2_s(:,j) && Va2_s(:,j)>Vc2_s(:,j) )
		Ia2_s(:,j)=Io;
	endif
	if ( Vb2_s(:,j)> Va2_s(:,j) && Vb2_s(:,j)>Vc2_s(:,j) )
		Ib2_s(:,j)=Io;
	endif	
	if ( Vc2_s(:,j)> Vb2_s(:,j) && Vc2_s(:,j)>Va2_s(:,j) )
		Ic2_s(:,j)=Io;
	endif
	if ( Va2_s(:,j)< Vb2_s(:,j) && Va2_s(:,j)<Vc2_s(:,j) )
		Ia2_s(:,j)=-Io;
	endif
	if ( Vb2_s(:,j)< Va2_s(:,j) && Vb2_s(:,j)<Vc2_s(:,j) )
		Ib2_s(:,j)=-Io;
	endif
	if ( Vc2_s(:,j)< Vb2_s(:,j) && Vc2_s(:,j)<Va2_s(:,j) )
		Ic2_s(:,j)=-Io;
	endif
endfor	



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Parallel Circuit Analysis %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Va1_p = 1.93185*Vp*sin(omegat);
Vb1_p = 1.93185*Vp*sin(omegat + (2*pi/3));
Vc1_p = 1.93185*Vp*sin(omegat - (2*pi/3));

Va2_p = 1.93185*Vp*sin(omegat + (pi/6));
Vb2_p = 1.93185*Vp*sin(omegat + (2*pi/3) + (pi/6));
Vc2_p = 1.93185*Vp*sin(omegat - (2*pi/3) + (pi/6));

Vrec1_p = max(max(Va1_p, Vb1_p),Vc1_p) - min(min(Va1_p, Vb1_p),Vc1_p);
Vrec2_p = max(max(Va2_p, Vb2_p),Vc2_p) - min(min(Va2_p, Vb2_p),Vc2_p);



rec1_p = false;
rec2_p = false;

% Initialize of variables
Vrec_p = zeros(size(omegat));

Ia1_p = zeros(size(omegat));
Ib1_p = zeros(size(omegat));
Ic1_p = zeros(size(omegat));
Ia2_p = zeros(size(omegat));
Ib2_p = zeros(size(omegat));
Ic2_p = zeros(size(omegat));

for i = [1:1:points+1]
	if Vrec1_p(:, i) >= Vrec2_p(:, i) 
		rec1_p = true;
		rec2_p = false;
		Vrec_p(:, i)  = Vrec1_p(:, i); % Output voltage on resistor
	else
		rec2_p = true;
		rec1_p = false;
		Vrec_p(:, i)  = Vrec2_p(:, i); % Output voltage on resistor
	endif	
	
	if rec1_p == true
		%"rect 1"
		if (Va1_p(:, i) > Vb1_p(:, i) && Va1_p(:, i) > Vc1_p(:, i)) 
			Ia1_p(:, i) = Io; % Current on the A phase
		endif
		if (Va1_p(:, i) < Vb1_p(:, i) && Va1_p(:, i) < Vc1_p(:, i))
			Ia1_p(:, i) = -Io;
		endif
		if (Vb1_p(:, i) > Va1_p(:, i) && Vb1_p(:, i) > Vc1_p(:, i)) 
			Ib1_p(:, i) = Io; % Current on the B phase
		endif
		if (Vb1_p(:, i) < Va1_p(:, i) && Vb1_p(:, i) < Vc1_p(:, i))
			Ib1_p(:, i) = -Io;
		endif
		if (Vc1_p(:, i) > Vb1_p(:, i) && Vc1_p(:, i) > Va1_p(:, i)) 
			Ic1_p(:, i) = Io; % Current on the C phase
		endif
		if (Vc1_p(:, i) < Vb1_p(:, i) && Vc1_p(:, i) < Va1_p(:, i))
			Ic1_p(:, i) = -Io;
		endif
	else 
		if rec2_p == true
			%"rect 2"
			if (Va2_p(:, i) > Vb2_p(:, i) && Va2_p(:, i) > Vc2_p(:, i)) 
				Ia2_p(:, i) = Io; % Current on the A' phase
			endif
			if (Va2_p(:, i) < Vb2_p(:, i) && Va2_p(:, i) < Vc2_p(:, i))
				Ia2_p(:, i) = -Io;
			endif
			if (Vb2_p(:, i) > Va2_p(:, i) && Vb2_p(:, i) > Vc2_p(:, i))
				Ib2_p(:, i) = Io; % Current on the B' phase
			endif
			if (Vb2_p(:, i) < Va2_p(:, i) && Vb2_p(:, i) < Vc2_p(:, i))
				Ib2_p(:, i) = -Io;
			endif
			if (Vc2_p(:, i) > Vb2_p(:, i) && Vc2_p(:, i) > Va2_p(:, i))
				Ic2_p(:, i) = Io; % Current on the C' phase 
			endif
			if (Vc2_p(:, i) < Vb2_p(:, i) && Vc2_p(:, i) < Va2_p(:, i)) 
				Ic2_p(:, i) = -Io;
			endif
		endif
	endif
endfor



%%%%%%%%%%%%%%%%%%%
% Output Graphics %
%%%%%%%%%%%%%%%%%%%


Ia1=Ia1_s;
Ia2=(Ia2_s-Ib2_s)./sqrt(3);
Ia3=Ia1_p*1.93185;
Ia4=(Ia2_p-Ib2_p).*1.93185./sqrt(3);

Ia=Ia1+Ia2+Ia3+Ia4;

%figure;
%hold on,
%grid;
%plot(omegat, Ia, ";I_a; r");
%%plot(omegat, Ia2, ";Ia2; r");
%%plot(omegat, Ia3, ";Ia3; g");
%%plot(omegat, Ia4, ";Ia4; b");
%
%xlabel('Angulo [rad]');
%ylabel('Curriente [A]');
%axis([0, 2*pi+1, -5, 5], "normal");
%print corr_sal_f.png;

% figure
% hold;
% grid;

% plot(omegat, Ia2*sqrt(3), ";Ia2_nf; m");
% plot(omegat, Ia3/1.93185, ";Ia3_nf; r");
% plot(omegat, Ia1, ";Ia1_nf; g");
% axis([0, 2*pi+1, -5, 5], "normal");

Vout = Vrec_s + Vrec_p;


Vmean = zeros(size(omegat));
Vmean(1, :) = mean(Vout); % Mean voltage of the output
Vmean(:, 1)
Vomax = max(Vout)
Vomin = min(Vout)
deltaVo = Vomax - Vomin

% Voltages in serie circuit 
%figure; % Plot voltages
%hold;
%grid;
%
%plot(omegat, Va1_s, ";Va1_s; k ");
%plot(omegat, Vb1_s, ";Vb1_s; r ");
%plot(omegat, Vc1_s, ";Vc1_s; y ");
%plot(omegat, Va2_s, ";Va2_s; m ");
%plot(omegat, Vb2_s, ";Vb2_s; b ");
%plot(omegat, Vc2_s, ";Vc2_s; g ");
%
%title('24 Pulse Rectifier');
%xlabel('Angle [rad]');
 %ylabel('Voltage [V]');
%%axis([0, 2*pi+1, 0, 1200], "normal");
%
%figure; % Plot voltages
%hold;
%grid;

% plot(omegat, Va1_s, ";Va1_s m .");
% plot(omegat, Vb1_s, ";Vb1_s b .");
% plot(omegat, Vc1_s, ";Vc1_s g .");
% plot(omegat, Va2_s, ";Va2_s; m ");
% plot(omegat, Vb2_s, ";Vb2_s; b ");
% plot(omegat, Vc2_s, ";Vc2_s; g ");

%plot(omegat, Vrec_s, ";Vrec_s; b .");
%plot(omegat, Vrec_p, ";Vrec_p; r .");
%
%plot(omegat, Vout, ";Vout; k ");
%
%title('24 Pulse Rectifier');
%xlabel('Angle [rad]');
%ylabel('Voltage [V]');
%axis([0, 2*pi+1, 0, 1200], "normal");
%
%print tensiones.png;

% figure; % Plot voltages
% hold;
% grid;

% plot(omegat, Va1_p, ";Va; m .");
% plot(omegat, Vb1_p, ";Vb; b .");
% plot(omegat, Vc1_p, ";Vc; g .");
% plot(omegat, Va2_p, ";Va'; m ");
% plot(omegat, Vb2_p, ";Vb'; b ");
% plot(omegat, Vc2_p, ";Vc'; g ");

% plot(omegat, Vrec1, ";Vrec1; b ");
% plot(omegat, Vrec2, ";Vrec2; r ");

% plot(omegat, Vrec_p, ";Vrec_p; k .");
% plot(omegat, Vmean, ";Vmean; m");

% title('12 Pulse Rectifier');
% xlabel('Angle [rad]');
% ylabel('Voltage [V]');
% axis([0, 2*pi+1, -200, 350], "normal");

% print tensiones_12.png;

% figure; % Plot currents after the transformers
% hold on;
% grid;

% plot(omegat, Ia1, ";Ia1_p; b .-");
% plot(omegat, Ia2, ";Ib1_p; r .-");
% plot(omegat, Ia3, ";Ic1_p; g .-");
% plot(omegat, Ia4, ";Ia2_p; c ");
% plot(omegat, Ia, ";Iout; k");

% title('24 Pulse Rectifier');
% xlabel('Angle [rad]');
% ylabel('Current [A]');
%axis([0, 2*pi+1, -2, 2], "normal");

% print corrientesA.png;

% figure; % Plot currents after the transformers
% hold on;
% grid;

% plot(omegat, Ia1_s, ";Ia1_s; b ");
% plot(omegat, Ib1_s, ";Ib1_s; r ");
% plot(omegat, Ic1_s, ";Ic1_s; g ");
% plot(omegat, Ia2_s, ";Ia2_s; c .-");
% plot(omegat, Ib2_s, ";Ib2_s; m .-");
% plot(omegat, Ic2_s, ";Ic2_s; k .-");


% title('24 Pulse Rectifier');
% xlabel('Angle [rad]');
% ylabel('Current [A]');
% axis([0, 2*pi+1, -2, 2], "normal");


Va_rms = Vp / sqrt(2)
Ia_rms = sqrt(mean(power(Ia, 2)))
Sa = Va_rms * Ia_rms
Po = mean( Vmean * mean(Io));
Pa = Po / 3;
dpF = 1;
PF = Pa / Sa * dpF

THD = sqrt((1/PF)^2 -1)