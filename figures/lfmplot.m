%% direct generate linear frequency modulation signal
i = 0:1023;
z = cos(39062.*pi.*((i - 512)/1024*16/625).^2);
plot(i, z);
% if your operating system is not Unix, please modify the path
print -dpdflatexstandalone '/tmp/lfm_simulation.tex';

%% direct digital synthesis
x = sin(2*pi*i/1024);
j = mod(int64((i - 512).^2./80 + 256), 1024);
for k = 1:1024
	if k == 512
		y(k) = 1;
	else
		y(k) = x(j(k));
	end
end
plot(i, y);
% the firgure is mostly same as the former, so i don't wanna print it
