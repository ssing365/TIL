### 05-1 DNS와 자원

### 도메인 네임과 네임 서버

- 도메인 네임
    - IP 주소와 대응되는 문자열 형태의 호스트 정보
    - [www.naver.com](http://www.naver.com) , [git.kernel.org](http://git.kernel.org) etc
    - 기억하기도 쉽고 IP 주소가 바뀌어도 도메인네임에 다시 대응하면 되므로 간편하다.
- 네임 서버
    - 도메인 네임과 IP주소는 네임 서버에서 관리한다.
- 도메인 네임 구조
    - 점을 기준으로 계층적으로 분류
        - 최상단에 루트 도메인(root domain)
            - .
        - 최상위 도메인(TLD; Top-Level Domain)
            - com, kr, net, org 등
        - 2, 3, 4단계 도메인 …
            - naver, google(2단계)
            - www(3단계)
- 전체 주소 도메인 네임(FQDN)
    
    ![스크린샷 2025-04-10 오후 5.55.05.jpg](./images/Chapter05/FQDN.jpg)
    
    - 도메인 네임을 모두 포함하는 도메인 네임
        - com으로 끝나는 도메인 네임은 많다.
            - [api.ex.com](http://api.ex.com), [mail.ex.com](http://mail.ex.com), [www.ex.com](http://www.ex.com) 등
        - 하지만 첫번째 부분까지 고려한 도메인 네임은 하나뿐
            - [www.ex.com](http://www.ex.com)
        - 이런 점에서 FQDN의 첫 번째 부분(www)을 **호스트 네임**이라 부른다.

<aside>

❓서브 도메인이란?

- 다른 도메인이 포함된 도메인
- google.com의 서브 도메인
    - mail.google.com
    - www.google.com
    - drive.google.com

google.com은 com을 포함하고 있기에 com의 서브도메인이다.

</aside>