1 => int counter;

while(counter <= 10){
    <<<counter>>>;
    counter + 1 => counter;
}


SinOsc osc => dac;
0.5 => osc.gain;

for(1 => int i; i <= 1000; i++){
    i => osc.freq;
    <<<i>>>;
    4::ms => now;
}