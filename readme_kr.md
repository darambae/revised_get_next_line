
# get_next_line (with bonus)

## 목차

  - [소개](#소개)
  - [기능](#기능)
  - [파일 관리에 사용되는 표준 함수들](#파일-관리에-사용되는-표준-함수들)
  - [보너스](#보너스)

## 소개

**get_next_line**는 C 프로젝트로, 파일 디스크립터(표준 입력 포함)에서 한 줄을 읽기 위한 함수를 제공하는 것을 목표로 합니다. 이 구현은 파일에서 효율적으로 한 줄씩 읽을 수 있으며, 여러 파일 디스크립터를 동시에 처리할 수 있습니다. 이 프로젝트는 메모리 관리와 동적 할당에 중점을 두어 입력을 읽는 동안 자원이 적절하게 관리되도록 합니다. **get_next_line** 작업을 통해 C에서 파일 처리에 대한 깊은 이해를 얻고 버퍼와 문자열을 다루는 기술을 향상시킬 수 있습니다.

## 기능

- 파일 디스크립터에서 줄 바꿈 문자('\n')를 포함한 줄을 읽음.
- 여러 파일 디스크립터를 동시에 처리.
- 동적 버퍼 할당을 통한 효율적인 메모리 사용.

## 파일 관리에 사용되는 표준 함수들

- `open()` : 파일을 열고 파일 디스크립터를 반환.
  - 프로토타입 : `int open(const char *pathname, int flags, mode_t mode);`
  - 예시 : `int fd = open("file.txt", O_RDONLY);`

- `read()` : 파일 디스크립터에서 데이터를 읽음.
  - 프로토타입 : `ssize_t read(int fd, void *buf, size_t count);`
  - 예시 : `ssize_t bytesRead = read(fd, buffer, 1024);`

- `close()` : 파일 디스크립터를 닫음.
  - 프로토타입 : `int close(int fd);`
  - 예시 : `close(fd);`

## 보너스

- 여러 파일 디스크립터를 동시에 처리.
- 읽은 줄을 반환하거나 더 이상 읽을 것이 없거나 오류가 발생하면 NULL을 반환.
