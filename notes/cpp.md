# msys32 좋은듯?

gcc, openssl 등 패키지 관리해 준다  
gcc 구버전 -> vscode debugger에서 array의 주소만 보였음 -> msys32로 gcc 설치 & 해결

# cout

```cpp
cout << 1; // unexpected result
```

ASCII(1) = SOH 이기 때문에 1을 출력하지 않는다.

```cpp
cout << (int)1; or cout << (string)1;
```

#
