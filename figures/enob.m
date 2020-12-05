%% import data
data = csvread('data/enob.csv');
% the first line is title
data(1, :) = [];
datsgn = data(:,2);

%% time domain
N = length(datsgn);
fs = 20e3;
t = [0:N-1]/fs;
plot(t, datsgn);
xlim([0 0.003]);
xlabel('$t$/s');
print -dpdflatexstandalone '/tmp/t.tex';

%% frequency domain
datfft = abs(fft(datsgn));
% filter direct component
datfft(1) = 0;
datfft = datfft(1:N/2);
f = [0:N/2-1]*fs/N;
plot(f, 20*log10(datfft));
xlabel('$f$/Hz');
ylabel('dB');
axis tight;
print -dpdflatexstandalone '/tmp/f.tex';

%% calculate enob
[maxval, pos] = max(datfft);
sig_rms = sqrt(sum(datfft(pos-3:pos+3).^2));
nos_rms = sqrt(sum(datfft(2:N/2).^2))-sig_rms;
snor = 20*log10(sig_rms/nos_rms);
enob = (snor-1.79)/6.02
