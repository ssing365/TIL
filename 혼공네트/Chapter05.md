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
        - **최상단에 루트 도메인(root domain)**
            - **.**
        - **최상위 도메인(TLD; Top-Level Domain)**
            - **com, kr, net, org 등**
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

- **DNS는 전세계에 분산되어 위치한다**

### 계층적 네임 서버

- 도메인 네임으로 IP 주소 알아내는법(리졸빙 하는 법)
    1. 클라와 가장 맞닿아있는 **로컬 네임 서버에 먼저**
        - 주로 ISP가 할당해주며, 공개 DNS 로컬네임서버로는 `8.8.8.8`  `8.8.4.4` 가 있다(구글).
    2. 루트 네임 → TLD 네임 → 책임 네임 순차적으로 
        - 해당 도메인을 관리하는 곳으로 안내받다가 책임 네임 서버가 최종 알아냄
            
            ![스크린샷 2025-04-12 오후 7.48.53.jpg](./images/Chapter05/cns.jpg)
            
        - 재귀적 질의와 반복적 질의 형태가 있다.
            - 재귀적 질의
                
                ![스크린샷 2025-04-12 오후 7.50.58.jpg](./images/Chapter05/jae.jpg)
                
                - 최종 응답 결과를 역순으로 전달
            - 반복적 질의
                
                ![스크린샷 2025-04-12 오후 7.52.37.jpg](./images/Chapter05/repeat.jpg)
                
                - 로컬 네임 서버가 네임 서버에 일일이 질의 응답 반복
        - 한계점 : 이런 질의는 8단계를 거치므로 전 세계적인 트래픽을 고려하면 과부하가 일어날 수 있다.
        - 보완 - **DNS 캐시** : 그래서 실제로는 네임 서버들이 기존에 응답받은 결과를 임시로 저장했다가 추후 같은 질의에 이를 활용하는 경우가 많다.
            - DNS 캐시를 활용하면 짧은 시간 안에 원하는 IP주소를 얻어낼 수 있다.
            - TTL이 있어 영원히 존재하지는 않는다.

### 자원을 식별하는 URI

- 자원(Resource) : 네트워크상의 메시지를 통해 주고받는 대상
- URI(Uniform Resource Identifier) : 자원을 식별할 수 있는 통일된 방식
    - URL(Uniform Resource Locator) : 위치를 이용해 자원을 식별
    - URN(Uniform Resource Name) : 이름을 이용해 자원을 식별
        - 잘 안씀

---

URL 형식

![스크린샷 2025-04-15 오후 1.22.49.jpg](./images/Chapter05/url.jpg)

1. scheme
    - 자원에 접근하는 방법
    - 일반적으로 사용하는 프로토콜 명시
    - `http://` `https://`
2. authority
    - 호스트를 특정할 수 있는 정보
    - IP주소, 도메인 네임
    - 콜론(:) 뒤에 포트 번호를 덧붙일수도 있다.
3. path
    - 자원이 위치한 경로
    - `/` 가 최상위 경로
4. query
    - HTTP는 요청과 응답 기반의 프로토콜인데, 요청할때 특정 조건을 붙일 수 있음 = 쿼리
5. fragment
    - 자원의 한 조각을 가리키기 위한 정보