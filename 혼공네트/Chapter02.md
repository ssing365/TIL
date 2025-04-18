### 02-1 이더넷

# 이더넷

- 현대 LAN, 특히 유선 LAN 환경에서 대중적으로 사용되는 기술
- 다양한 **통신 매체**의 규격, 송수신되는 **프레임**의 형태, 프레임을 주고받는 방법 등이 정의된 기술
    - **물리 계층**에서 사용되는 케이블 → 이더넷 규격을 따름
    - **데이터링크 계층**에서 주고받는 프레임(PDU) → 이더넷 프레임 형식 따름
- 물리 계층과 데이터링크 계층의 장비 모두 특정 이더넷 표준을 이해하고 따른다고 봐도 무방
- IEEE 802.3
    - 이더넷 관련 다양한 국제 표준들의 모음
        - 표준 = 여러 버전들의 모음
        - 802.3u, 802.3ab처럼 뒤에 알파벳으로 버전 표현
    - **이더넷 표준에 따라 지원되는 네트워크 장비, 통신 매체 종류, 전송 속도 등이 달라짐**

### 1. 물리 계층 관련 이더넷 기술(통신 매체)

- 통신 매체 표기 형태
    - IEEE 802.3i 케이블, IEEE 802.3u 케이블처럼 표기하지 않음
    - 통신 매체의 속도와 특성을 파악하기 쉽도록 다음과 같이 표기
        
        <aside>
        
        전송속도BASE-추가특성
        
        </aside>
        
        - ex) 1000BASE-SX, 2.5GBASE-T
        1. 전송 속도
            - 지원하는 최대 속도 표기
            - 숫자만 표기되어 있으면 Mbps 속도, G가 붙어 있으면 Gbps 속도.
        2. BASE
            - BASEband의 약자로, 변조 타입을 의미한다.
            - 대부분의 이더넷 통신 매체는 BASE 사용
        3. 추가 특성
            - 전송 가능한 최대 거리, 물리 계층 인코딩 방식, 레인 수 등 다양한 특성을 표기하는데, **가장 중요한건 통신매체의 종류**
            
            ### 통신 매체 종류
            
            | 추가 특성 표기(통신 매체 종류) | 케이블 종류 |
            | --- | --- |
            | C | 동축 케이블 |
            | T | 트위스티드 페어 케이
            케이블 |
            | S | 단파장 광섬유 케이블 |
            | L | 장파장 광섬유 케이블 |
            - 트위스티드 페어 케이블 - 구리 선을 이용
            - 광섬유 케이블 - 빛을 이용
- 예시
    - 10BASE-T 케이블 : 10Mbps 속도를 지원하는 트위스티드 페어 케이블
    - 1000BASE-SX 케이블 : 1000Mbps 속도를 지원하는 단파장 광섬유 케이블
    - 1000BASE-LX 케이블 : 1000Mbps 속도를 지원하는 장파장 광섬유 케이블
    
    ![스크린샷 2025-03-15 오후 8.04.32.jpg](./images/Chapter02/Cable.jpg)
    

### 2. 데이터링크 계층 관련 이더넷 기술(이더넷 프레임 형식)

- 현대 유선 LAN 환경은 대부분 이더넷을 기반으로 구성되므로 호스트가 데이터링크 계층에서 주고받는 프레임 형식도 정해져 있다.
- 즉, 이더넷 네트워크에서 주고받는 프레임인 **이더넷 프레임** 형식은 정해져 있다.

### 이더넷 프레임

- 캡슐화를 거쳐 송신
    - 상위 계층 정보(데이터) + 헤더 + 트레일러
- 역캡슐화를 거쳐 수신
    - 헤더, 트레일러 제거 후 상위 계층으로 올려 보냄

![스크린샷 2025-03-15 오후 9.39.01.jpg](./images/Chapter02/EthernetFrame.jpg)

- 헤더
    - 프리앰블
        - 이더넷 프레임의 시작을 알리는 8바이트 크기 정보
        - 수신지는 이를 통해 이더넷 프레임이 온다고 알 수 있음
    - **수신지 MAC 주소와 송신지 MAC 주소**
        - MAC주소
            - 물리적 주소
            - 일반적으로 고유하고 변경되지 않아, LAN 내의 송수신지를 특정할 수 있다.
            - 네트워크 인터페이스(NIC)마다 부여되는 6바이트(48비트)길이 주소
            - 한 컴퓨터에 NIC가 여러 개 있다면 MAC 주소도 여러 개 있을 수 있다.
- 페이로드(데이터)
    - 상위 계층에서 전달받거나 상위 계층으로 전달해야 할 내용
    - 최대 크기 1500바이트
    - 최소 크기 46바이트
        - 46바이트 이하의 데이터라면 크기를 맞추기 위해 패딩(0)이 채워진다.
- 트레일러
    - FCS
        - 수신한 이더넷 프레임에 오류가 있는지 확인하기 위한 필드
        - CRC라는 오류 검출용 값이 들어있다.
        - 송신지에서 프리앰블을 제외한 나머지 필드 값을 바탕으로 CRC를 계산하고, FCS필드에 명시한다.
        - 수신지에서 프리앰블을 제외한 나머지 필드 값을 바탕으로 CRC를 계산하고, FCS필드값과 비교한다.
            - 비교값이 일치하지 않으면 프레임에 오류가 있다고 판단하고 프레임을 폐기한다.
    

이더넷 이외 다른 LAN 기술?

- 토큰이 있어야만 정보를 전달할 수 있는 **토큰링** 기술

### 02-2 NIC와 케이블

### NIC

: 호스트를 네트워크(LAN)에 연결하는 장비

- **통신 매체에 흐르는 신호를 호스트가 이해하는 프레임으로 변환하거나 그 반대로 변환**
- **호스트가 네트워크를 통해 송수신하는 정보는 NIC를 거침**
- 네트워크와의 연결점을 담당한다는 점에서 네트워크 인터페이스 역할을 수행한다고도 함
- 어떤 프레임이 자신에게 도달했을 때, 프레임 MAC 주소가 자신과 관련 없는 수신지라면 폐기할 수 있음
- 많은 트래픽을 감당해야하는 호스트는 NIC 장비를 추가하기도 함

### 케이블

### 트위스티드 페어 케이블

: 구리 선으로 전기 신호를 주고 받는 매체

- 생김새 = 커넥터 + 케이블 본체
    - 커넥터 : 주로 RJ-45
    - 본체 : 구리선이 두가닥씩 꼬아져있음
- 실드에 따른 분류
    - 구리선은 **노이즈(전기 신호를 왜곡시킬 수 있는 간섭)**에 민감하다
        
        ⇒ 실드 필요 (브레이드 실드 or 포일)
        
        브레이드 실드 : 그물 모양의 철사
        
        포일 실드
        
        - U : 실드 없음
        - S : 브레이드 실드
        - F : 포일 실드
        
        `X/YTP` 
        
        - `X` : 케이블 외부를 감싸는 실드 명시부분
        - `Y` : 꼬인 구리 선 쌍을 감싸는 실드 명시부분
        - ex) S/FTP U/UTP
- 카테고리에 따른 분류
    - 카테고리가 높을수록 대역폭, 전송률이 높아짐
    - Cat5, Cat5e, Cat6, Cat6a, Cat7, Cat8

<aside>

우리집공유기 케이블😀

- Cat5e, UTP
</aside>

### 광섬유 케이블

: 빛을 이용해 정보를 주고받는 케이블

- 전기보다 빠르고, 먼 거리 전송 가능
- 노이즈로 부터 간섭도 적어 대륙간 네트워크 연결에도 사용
- 생김새 = 커넥터 + 케이블 본체
    - 커넥터가 다양
        - LC, SC, FC, ST etc
    - 본체
        - 코어를 클래딩으로 감싸는구조
        - 코어에 실질적으로 빛이 흐른다
- 분류
    - 코어의 지름에 따른 분류
        
        (케이블 본체의 색으로 구분한다)
        
        - 싱글 모드 광섬유 케이블
            - 지름이 매우 작다
            - 빛의 이동경로가 보통 하나
            - 장파장 이용
            - 신호 손실이 적어 장거리 전송에 적합
            - 비용 높다
        - 멀티 모드 광섬유 케이블
            - 코어 지름이 싱글모드보다 큼(머리카락 두께 정도)
            - 빛이 여러 경로로 이동 가능
            - 단파장 이용
            - 신호 손실이 클 수 있어 장거리 전송에 부적합

### 02-3 허브

(요즘 잘 안씀 → 충돌 때문에)

![스크린샷 2025-03-25 오후 7.08.40.jpg](./images/Chapter02/hub.jpg)

- 허브
    - 물리계층에서 여러 호스트를 연결하는 장치
    - 물리계층에는 주소 개념이 없기 때문에 전달 받은 신호를 다른 모든 포트로 그대로 다시 내보내는 기능만 한다.
        - 이더넷 네트워크의 허브는 이더넷 허브
        - 신호가 감소하거나 왜곡되는 것을 방지하기 위해 전기 신호를 증폭시키는 리피터를 포함하여 리피터 허브라고도 한다.
    - 반이중 모드로 통신한다
        - 1차선 도로를 생각하면 된다.
        - 따라서 충돌이 생길 가능성이 있다. (반이중, 모든 포트로 전송해야해서)
        - 충돌이 생길 수 있는 영역 : **콜리전 도메인**
        - 콜리전 도메인을 줄이기 위해 CSMA/CD 프로토콜 사 용
            - CSMA/CD
                - CS : 캐리어 감지 - 전송중인 게 있나 확인
                - MA : 다중 접근 - 충돌이 발생한 상황
                - CD : 충돌 검출 - 충돌이 발생했다고 잼 신호를 보내 알림

### 02-4 스위치

- 허브의 충돌 문제 해결 : 스위치
    - 전달받은 신호를 수신지 호스트가 연결된 포트로만 보내고, 전이중 모드로 통신하면 된다.

⇒ **스위치**는 MAC 주소를 학습할 수 있어 전달받은 신호를 원하는 포트로만 내보낼 수 있다. 또한 전이중 통신이 가능하다.

- 스위치의 두 가지 주요 특징 (MAC 주소 학습, VLAN)
    - 스위치가 주소를 학습하는 법
        - **MAC 주소 테이블**에 스위치의 **포트**와 연결된 **호스트의 MAC 주소** 관계 정보를 담는다.
            
            ![스크린샷 2025-03-27 오후 5.18.00.jpg](./images/Chapter02/MAT.jpg)
            
        
        <aside>
        
        1. 신호를 보낸 포트의 프레임에서 MAC 송신지 주소를 파악하고, 포트와 주소를 테이블에 저장한다.
        2. 수신지의 포트는 아직 모르므로, 허브처럼 모든 포트에 신호를 보낸다. (플러딩)
        3. 각 호스트는 프레임의 수신지 주소와 자신의 MAC 주소를 비교하고, 다르면 프레임 폐기, 같으면 응답 프레임을 스위치로 반환한다.
        4. 응답 프레임을 받은 포트와 MAC 주소를 테이블에 저장한다.
        5. 다음에 정보를 받았을 때, 다른 주소의 포트로는 정보를 보내지 않고(필터링) 일치하는 주소의 포트로만 정보를 보낸다.(포워딩)
        6. 에이징 : 일정 시간 프레임을 전송받지 못한 항목 삭제
        </aside>
        
        - 플러딩(Flooding)
            
            A → C 정보 전송
            
            ![스크린샷 2025-03-27 오후 5.27.34.jpg](./images/Chapter02/flooding.jpg)
            
        - 필터링, 포워딩
            
            ![스크린샷 2025-03-27 오후 5.28.05.jpg](./images/Chapter02/filtering.jpg)
            
        - 에이징
        
        <aside>
        
        브릿지란?
        
        - 네트워크 영역을 구획하여 콜리전 도메인을 나누거나 네트워크를 확장하는 어떤 것
        - 단일장비로는 잘 안씀(스위치 많이 씀)
        - 위 개념적인 용어로 많이 사용됨
        </aside>
        
    - VLAN
        
        : 한 대의 스위치로 가상의 LAN을 만들어 네트워크상 불필요한 트래픽을 줄이고 효율을 높인다.
        
        ![스크린샷 2025-03-27 오후 5.29.53.jpg](./images/Chapter02/VLAN.jpg)
        
        - 사실상 다른 VLAN을 가지면 거리에 상관없이 다른 브로드캐스트 도메인(다른 LAN)을 가지게 되므로 다른 LAN 간의 통신을 할 때는 상위 계층(네트워크 계층)의 장비가 필요하다.
        - 포트 기반 VLAN
            - 스위치의 포트가 VLAN을 결정하는 방식
        - MAC 기반 VLAN
            - 사전에 설정된 MAC 주소에 따라 VLAN이 결정됨
        - VLAN 트렁킹을 통해 낭비되는 포트를 최소화하며 VLAN을 구성할 수 있다.