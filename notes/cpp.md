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

# Compile Environment

백준 cpp 컴파일 환경과 vscode 컴파일 환경이 다름 -> 다른 동작 가능성 있음  
ex) header 자동 추가 유무 등

**확실하게 하려면 같은 컴파일 환경에서 체크하자!**
