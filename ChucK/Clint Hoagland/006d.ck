TriOsc osc => dac;

0.5 => osc.gain;

[0, 4, 7] @=> int major[];
[0, 3, 7] @=> int minor[];

48 => int offset;
int position;

7::ms => dur eighth;


while(true){
    0 => position;

    for(0 => int i; i < 4; i++){

        i => position;

        for(0 => int j; j < 3 ; j++){
            
            Std.mtof(major[j] + offset + position) => osc.freq;
            eighth => now;
        }
    }
}