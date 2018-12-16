# Design Doc
Here is information about the design of the program

[x] Preprocessing
[x] 1. split tracks across arduinos

[ ] Runtime
[x] 1. establish connection with req/ack
[ ] 2. constantly sync


### Runtime 2.
Master sends out a pulse every `n` ticks.
Slaves constantly read from master. Upon receiving HIGH, adapts delay in Playtune.

Now, for this