//MIDI uses numbers 0 to 127 to represent notes
SinOsc osc => dac;

0.5 => osc.gain;

for(0 => int i; i <= 127; i++){
    Std.mtof(i) => osc.freq;
    <<<i, Std.mtof(i)>>>;
    100::ms => now;
}