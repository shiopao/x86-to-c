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
### Conclusion
