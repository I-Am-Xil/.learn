SinOsc osc => dac;
0.25 => osc.gain;

[110, 220, 440, 660, 770, 880, 1320] @=> int frequencies[];

[60, 62, 64, 65, 67, 69, 71, 72, 74] @=> int pitches[];

for(0 => int i; i < pitches.cap(); i++){
    Std.mtof(pitches[i]) => osc.freq;
    200::ms => now;
}