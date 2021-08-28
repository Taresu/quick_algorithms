# quick_algorithms

This practice is intended to analyze the response time of Quick Sort algorithms in different ways.

Paths analyzed:
* Crescent sorting, with pivot being the array element of the last position;
* Crescent sorting, with random pivot.
* 
* **apparently not working!**
* Decrescent sorting, with pivot being the array element of the last position;

* **not done yet**
* Decrescent sorting, with random pivot.

Benchmark / Time average:
Elements:
  * |10| 
    - Crescent-LastPositionPivot: 0.00s; 
    - Crescent-RandomPivot: 0.00s;
    - Decrescent: 0.00s.
    - Decrescent-RandomPivot: ?.
  * |100|
    - Crescent-LastPositionPivot: 0.00s; 
    - Crescent-RandomPivot: 0.00s.
    - Decrescent: 0.00s.
    - Decrescent-RandomPivot: ?.
  * |1.000| 
    - Crescent-LastPositionPivot: 0.02s; 
    - Crescent-RandomPivot: 0.00s.
    - Decrescent: 0.00s.
    - Decrescent-RandomPivot: ?.
  * |10.000| 
    - Crescent-LastPositionPivot: 2.88s; 
    - Crescent-RandomPivot: 0.00s.
    - Decrescent: 0.32s.
    - Decrescent-RandomPivot: ?.
  * |100.000| 
    - Crescent-LastPositionPivot: 28.99s; 
    - Crescent-RandomPivot: 0.01s.
    - Decrescent-LastPositionPivot: 28.96s.
    - Decrescent-RandomPivot: ?.
  * |1.000.000|
    - Crescent-LastPositionPivot: Segmentation Fault; 
    - Crescent-RandomPivot: 0.13s.
    - Decrescent: Segmentation Fault.
    - Decrescent-RandomPivot: ?.

