# quick_algorithms

This practice is intended to analyze the response time of Quick Sort algorithms in different ways.
Paths analyzed:
* Randomic sorting, with random pivot
* Crescent sorting, with pivot being the last position array element
* Crescent sorting, with random pivot
* Decrescent sorting (not working!)

Benchmark / Time average:
Elements:
  * |10| 
    - Random: 0.00s; 
    - Crescent-LastPositionPivot: 0.00s; 
    - Crescent-RandomPivot: 0.00s;
    - Decrescent: ?.
  * |100|
    - Random: 0.00s;
    - Crescent-LastPositionPivot: 0.00s; 
    - Crescent-RandomPivot: 0.00s.
    - Decrescent: ?.
  * |1.000| 
    - Random: 0.00s;
    - Crescent-LastPositionPivot: 0.02s; 
    - Crescent-RandomPivot: 0.00s.
    - Decrescent: ?.
  * |10.000| 
    - Random: 0.00s;
    - Crescent-LastPositionPivot: 2.88s; 
    - Crescent-RandomPivot: 0.00s.
    - Decrescent: ?.
  * |100.000| 
    - Random: 0.01s;
    - Crescent-LastPositionPivot: 627.66s; 
    - Crescent-RandomPivot: 0.01s.
    - Decrescent: ?.
  * |1.000.000|
    - Random: 0.13s;
    - Crescent-LastPositionPivot: ?; 
    - Crescent-RandomPivot: 0.13s.
    - Decrescent: ?.

