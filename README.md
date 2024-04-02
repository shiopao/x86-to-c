# x86-to-C Interface
**Input:** Scalar variable n (integer) contains the length of the vector; Vectors X and Y are both single-precision float. <br>
**Process:** $`Y[i] = X[i - 3] + X[i - 2] + X[i - 1] + X[i] + X[i + 1] + X[i + 2] + X[i + 3]`$ <br>
**Output:** Store result in vector Y. Display the result of 1st ten elements of vector Y for all versions of kernel (i.e., C and x86-64).
### Debug Mode
Full documentation for debug mode tests can be found [here](/screenshots/debug/).
#### Vector size n = 2<sup>20</sup>
<img src="/screenshots/debug/20/debug_20_1.jpg" width="250"/> <img src="/screenshots/debug/20/debug_20_6.jpg" width="250"/> <br>
```
Average execution time for C version: 0.004533 seconds
Average execution time for x86-64 version: 0.003533 seconds
```

#### Vector size n = 2<sup>24</sup>
<img src="/screenshots/debug/24/debug_24_1.jpg" width="250"/> <img src="/screenshots/debug/24/debug_24_6.jpg" width="250"/> <br>
```
Average execution time for C version: 0.149633 seconds
Average execution time for x86-64 version: 0.123033 seconds
```

#### Vector size n = 2<sup>28</sup>
<img src="/screenshots/debug/28/debug_28_1.jpg" width="250"/> <img src="/screenshots/debug/28/debug_28_6.jpg" width="250"/> <br>
```
Average execution time for C version: 2.364267 seconds
Average execution time for x86-64 version: 1.928200 seconds
```
---
### Release Mode
Full documentation for release mode tests can be found [here](/screenshots/release/).
#### Vector size n = 2<sup>20</sup>
<img src="/screenshots/release/20/release_20_1.jpg" width="250"/> <img src="/screenshots/release/20/release_20_6.jpg" width="250"/> <br>
```
Average execution time for C version: 0.004500 seconds
Average execution time for x86-64 version: 0.004567 seconds
```

#### Vector size n = 2<sup>24</sup>
<img src="/screenshots/release/24/release_24_1.jpg" width="250"/> <img src="/screenshots/release/24/release_24_6.jpg" width="250"/> <br>
```
Average execution time for C version: 0.090867 seconds
Average execution time for x86-64 version: 0.076933 seconds
```

#### Vector size n = 2<sup>28</sup>
<img src="/screenshots/release/28/release_28_1.jpg" width="250"/> <img src="/screenshots/release/28/release_28_6.jpg" width="250"/> <br>
```
Average execution time for C version: 1.800167 seconds
Average execution time for x86-64 version: 1.361167 seconds
```
---
### Analysis
The average execution times of the C and x86-64 Assembly implementations for the stencil operation were compared across different vector sizes and build configurations (Debug and Release). The experiments involved running 30 tests for each configuration with vector sizes of 2<sup>20</sup>, 2<sup>24</sup>, and 2<sup>28</sup>. 
When executed using the Debug build configuration, the average execution times of the C code ranged from 0.004533s to 2.364267s. While the average execution time of the x86-64 Assembly code ranged from 0.003533s to 1.928200s. The execution time of both code versions increased for larger vector sizes as expected. The x86-64 Assembly version is noticeably faster than the C version of the code.
The same tests were done using the Release build configuration. They are generally faster than the average execution times of the Debug build configuration since using Release allows for optimization. With the C code version executing for an average range of 0.004500s to 1.800167s, and the x86-64 Assembly code version ranging from 0.004567s to 1.361167s. Still, the x86-64 Assembly code executes faster than the C code version. 

---
### Conclusion
Through this project, the developers have learned that there is a significant performance advantage when a low level programming language such as x86-64 Assembly is implemented alongside a C program. This is because using Assembly allows for direct control over hardware resources, and CPU instructions can be utilized for more efficient processing of operations. Using Assembly also results in faster execution times because it does not need to pass through a compiler, unlike C and other high level languages. This among other factors can provide significant benefits in performance that a programmer can utilize. 

