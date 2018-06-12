#include <stdio.h>
int* quick_sort (int data[],int left, int right);
/*
거북이는 이제 어떤 것에도 흥미를 느끼지 않는다. 그 이유는 거북이가 300년동안 살았고, 그 동안 모든 것들을
다 해보았기 때문이다. 거북이는 시간을 떼우는 무엇인가를 하려고 한다.
이번 주말에 거북이는 거북이 세계에서 매우 유명한 게임인 "가장 큰 직사각형 만들기"를 해보려고 한다.

이 게임을 시작하기 전에 거북이는 양의 정수 네 개를 머릿 속에 생각해야 한다.
한 방향으로 움직이기 시작하고 90도 회전한 뒤에 새로운 방향으로 움직인다.
이런 식으로 세 번 90도 회전을 하고, 네 번 앞으로 움직여서 선 분 네 개를 만들어야 한다.

거북이가 선분을 그릴 때 움직여야 하는 걸음의 수는 생각해 놓은 네 정수중 하나이다.
이 때, 한 정수를 각각 한 번씩 사용해야 한다.
거북이가 정수를 사용하는 순서에 따라서 다양한 모양이 만들어진다. 어떤 모양은 직사각형을 만들 수 없기도 한다.

거북이가 만들 수 있는 가장 큰 직사각형을 계산하는 프로그램을 작성하시오.
*/
int* quick_sort (int data[],int left, int right){
  int i,j,key,temp;

  if (left < right){ //만일 왼쪽이 오른쪽보다 작다면
    i = left;
    j = right+1;
    key = data[left]; //왼쪽을 데이타 배열에 넣는다.
    do{
      do{
        i++;
      }while (data[i]<key);
      do {
        j--;
      }while(data[j]>key);
      if(i<j){
        temp = data[i];
        data[i] = data[j];
        data[j] = temp;
      }
    }while(i<j);

    temp = data[left];
    data[left] = data[j];
    data[j] = temp;
    quick_sort(data, left, j-1);
    quick_sort(data, j+1, right);
  }

  return data;

}


int main() {

    printf("거북이가 움직일 4정수를 입력해주세요 \n");
    int gubook[4] = {0};
    int i = 0;
    for(i=0;i<4;i++){scanf("%d",&gubook[i]);}
    int* jung = quick_sort(gubook,0,3);

    printf("%d \n", jung[0]*jung[2]);
  return 0;
}
