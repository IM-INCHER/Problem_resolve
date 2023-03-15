# cardinal_to_roman.cpp
## 정수를 로마숫자로 변경하는 cpp입니다.

![week2_1](https://user-images.githubusercontent.com/53209052/225307905-56e7befa-645d-4d1d-9877-784e3e467053.png)
![week2_2](https://user-images.githubusercontent.com/53209052/225308659-3ca7042e-6b2e-4878-b287-f0b574c42519.png)

1. int형 배열과 string형 배열을 만들어 각각 로마숫자에 해당하는 문자와 그 값을 넣어준다.
2. for문을 이용하여 values배열의 길이만큼 반복한다.
3. num이 values[i] 보다 작아질때 까지 values[i]를 빼고 string roman에 symbols[i]를 더해준다.

# roman_to_cardinal.cpp
## 로마숫자를 정수로 변경하는 cpp입니다.
![week2_3](https://user-images.githubusercontent.com/53209052/225312129-4d5fc784-d423-4d1c-b4d9-7af652f83350.png)
![week2_5](https://user-images.githubusercontent.com/53209052/225312145-785e32fd-0fae-4800-9f3f-7955ee1adb6d.png)

입력받은 값을 그에 대응하는 숫자로 변환하여 반환하는 함수입니다.   
입력받은 값이 잘못 되었을 경우 -1을 반환합니다.

![week2_4](https://user-images.githubusercontent.com/53209052/225312136-9e3f3dca-725d-4123-b5bb-e0ccdaed6425.png)

입력 받은 string의 길이만큼 반복합니다.   
입력받은 글자의 한글자 씩 비교하며 위 함수를 이용해 값을 더해줍니다   
만약 앞의 글자가 뒤에 글자보다 작은 글자면 -1을 곱해여 총값에서 빼줍니다.   