# Design Doc
Here is information about the design of the program

Preprocessing
- [x] 1. split tracks across arduinos
 
Runtime
- [x] 1. establish connection with req/ack
- [ ] 2. constantly sync

Build system
- [ ] Merge dual and generate scripts.
- [ ] Improve script to reflect this document.



### Runtime continual sync
Master sends out a pulse every `n` ticks.
Slaves constantly read from master. Upon receiving HIGH, adapts delay in Playtune.

Now, for this we will have to adapt the playtune library, so that every wait tick is counted.
