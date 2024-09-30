1::second / 2 => dur beat;

SinOsc osc => dac;

200 => osc.freq;
0.5 => osc.gain;

beat => now;

300 => osc.freq;

beat / 2 => now;

400 => osc.freq;

beat / 2 => now;