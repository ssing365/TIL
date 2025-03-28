### 03-1 LAN을 넘어서는 네트워크 계층

- 물리 계층, 데이터링크 계층의 기술만으로는 LAN을 넘어서 다른 네트워크 통신하는데 한계가 있다.
    - 다른 네트워크까지의 경로 파악 어려움
        
        → 네트워크 계층의 라우팅으로 해결
        
    - MAC 주소 만으로 모든 네트워크의 모든 호스트 위치를 특정하기 어렵다.
        
        → 네트워크 계층의 IP 주소 체계로 해결
        
        - MAC주소는 NIC에 고정 할당되는 물리주소
        - IP주소는 논리주소
            - DHCP라는 특정 프로토콜로 IP주소를 자동 할당받거나 사용자가 직접 할당할 수 있다.

### 인터넷 프로토콜 (IP)

- IP의 주요 기능 두 가지
    1. IP 주소 지정
        
        : IP 주소로 송수신 대상 지정
        
    2. IP 단편화
        
        : 전송하고자 하는 패킷 크기가 MTU라는 최대 전송 단위보다 클 경우 이를 MTU 크기 이하의 패킷으로 나누는 것
        
        - MTU
            - 일반적으로 최대 1500 바이트(2계층 데이터링크 계층의 페이로드 최대 크기)
            - IP 헤더도 MTU 크기에 포함된다. MTU = IP헤더 + IP페이로드
            - MTU이하로 나눠진 패킷은 수신지에서 재조합된다.
- IPv4
    
    ![스크린샷 2025-03-28 오후 2.55.15.jpg](./images/Chapter03/IPv4.jpg)
    
    - 8비트로 표현된 옥텟 4개(10진수)로 구성(총 32비트, 즉 2의 32승 개의 주소 표현 가능)
    - **헤더의 주요 필드**
        1. **식별자**
            - 재조합할때 어떤 메시지인지 식별하기 위한 필드
        2. **플래그**
            
            ![스크린샷 2025-03-28 오후 2.56.04.jpg](./images/Chapter03/flag.jpg)
            
            - **DF**(Don’t Fragment)
                - 단편화 허용/금지 여부
            - **MF**(More Fragment)
                - 뒤에 더 단편화된 패킷이 오는지 알림
                - 1이면 전송될 패킷이 더 있고, 0이면 마지막 패킷이라는 뜻
        3. **단편화 오프셋**
            
            ![스크린샷 2025-03-28 오후 2.56.37.jpg](./images/Chapter03/fragment.jpg)
            
            - 처음 단편화된 패킷으로부터 얼마나 떨어져있는지 알림
            - 패킷이 무작위 순서로 수신지에 도착하므로, 수신지에서 이 단편화오프셋을 토대로 순서를 맞춰 재조합한다.
        4. **TTL**(Time to live)
            
            ![스크린샷 2025-03-28 오후 2.56.54.jpg](./images/Chapter03/ttl.jpg)
            
            - 패킷의 수명
            - 홉마다 TTL이 1씩 감소하고 0이되면 패킷 폐기됨
                - 홉 : 패킷이 라우터 또는 호스트에 한 번 전달 되는 것
            - 네트워크 상 무의미한 패킷이 떠다니는것을 방지하기 위함
        5. **프로토콜**
            - 상위 계층이 어떤 프로토콜인지 알림
            - TCP:6, UDP:17
        6. **송신지 IP주소**
            - 패킷을 **보낸 노드의 IPv6 주소**
        7. **수신지 IP주소**
            - 패킷을 **받을 최종 목적지 노드의 IPv6 주소**
- IPv6
    - IPv4의 주소 개수 한계를 보완하고, 효율성과 확장성을 고려해 설계됨.
        
        ![스크린샷 2025-03-28 오후 2.57.25.jpg](./images/Chapter03/IPaddress.jpg)
        
    - **128비트 주소 체계**로, `:`(콜론)으로 구분된 8개 그룹의 **16진수**로 표현됨
        - **2^128 개의 주소**(약 3.4 x 10^38개) 사용 가능
    - 헤더의 주요 비트
        
        ![스크린샷 2025-03-28 오후 2.58.07.jpg](./images/Chapter03/v6header.jpg)
        
        1. **다음 헤더**
            
            ![스크린샷 2025-03-28 오후 2.58.30.jpg](./images/Chapter03/nextheader-1.jpg)
            
            ![스크린샷 2025-03-28 오후 2.58.44.jpg](./images/Chapter03/nextheader-2.jpg)
            
            - 다음 헤더는 **기본 헤더 뒤에 추가적인 확장 헤더** 또는 **최종 프로토콜(TCP/UDP 등)** 을 가리킴
            - IPv6는 추가적인 헤더가 필요할 경우, **기본헤더와 페이로드 사이에 확장헤더라는 추가**
            - 확장 헤더는 여러개 꼬리를 물듯 추가될 수 있다. 
            (확장 헤더마다 다음 헤더 필드 포함)
                - 홉 간 옵션 확장 헤더
                - 수신지 옵션 확장 헤더
                - 단편화 확장 헤더
                    
                    ![스크린샷 2025-03-28 오후 2.59.09.jpg](./images/Chapter03/v6fragment.jpg)
                    
                    - **다음 헤더** (이후 헤더 지정)
                    - **단편화 오프셋**(IPv4와 기능 동일)
                    - **식별자**(IPv4와 기능 동일)
                    - **M 비트**(IPv4의 MF필드와 기능 동일)
                        
                        → 마지막 조각인지 표시
                        
        2. **홉 제한**
            - IPv4의 TTL 필드와 기능 동일
            - **패킷이 거칠 수 있는 최대 라우터 수 지정** (라우터를 지날 때마다 1씩 감소)
            - 0이 되면 패킷 폐기
        3. **송신지 IP주소**
            - 패킷을 **보낸 노드의 IPv6 주소**
        4. **수신지 IP주소**
            - 패킷을 **받을 최종 목적지 노드의 IPv6 주소**

<aside>

**IPv4 헤더는 가변, IPv6 헤더는 고정인 이유**

✅ **IPv4 헤더가 가변적인 이유**

IPv4는 **기본 헤더(20바이트)** 외에도 **옵션 필드(최대 40바이트)** 를 추가할 수 있어 **헤더 크기가 20~60바이트로 변동**될 수 있음.

- 옵션 필드는 특정 기능(예: 보안, 경로 기록 등)이 필요할 때만 추가됨
- 따라서 **패킷마다 헤더 크기가 달라질 수 있음**
- 라우터가 패킷을 처리할 때, **헤더 크기를 확인하고 분석해야 하므로 성능 저하** 가능성 있음

✅ **IPv6 헤더가 고정적인 이유**

IPv6는 **기본 헤더 크기를 40바이트로 고정**하여 **일관된 성능과 빠른 패킷 처리**를 목표로 함.

- IPv4처럼 **옵션 필드를 기본 헤더에 포함하는 대신, 확장 헤더(Extension Header)로 분리**
- 필요할 때만 확장 헤더를 추가하므로 **기본적인 네트워크 성능을 저하시키지 않음**
- **라우터는 고정 크기의 헤더만 읽고, 확장 헤더는 목적지에서 처리** → **라우터 부담 감소 & 성능 향상**

**📌 결론:**

- **IPv4**: 헤더에 옵션 필드가 포함될 수 있어 **가변 크기(20~60바이트)**
- **IPv6**: **기본 헤더는 항상 40바이트로 고정** + 추가 기능은 **확장 헤더로 분리**하여 네트워크 성능 최적화 🚀
</aside>

### ARP

: **동일 네트워크 내**에 있는 호스트 **IP 주소(논리)를 통해** **MAC 주소(물리)를 알아내기 위한 프로토콜**

1. **ARP 요청**
    
    ![스크린샷 2025-03-29 오후 11.17.45.jpg](./images/Chapter03/ARPreq.jpg)
    
    - **브로드캐스트**(네트워크 내 모든 호스트에게) 메시지 전송
2. **ARP 응답**
    
    ![스크린샷 2025-03-29 오후 11.17.57.jpg](./images/Chapter03/ARPres.jpg)
    
    - **유니캐스트(1:1 통신)**
    - ARP 요청 메시지가 자기 IP와 다르면 무시, 일치하면 **ARP 응답**을 전송
3. **ARP 테이블 갱신**
    
    ![스크린샷 2025-03-29 오후 11.18.28.jpg](./images/Chapter03/ARPtable.jpg)
    
    - ARP를 활용할 수 있는 모든 호스트는 **ARP 테이블**이라는 정보를 유지한다.

<aside>

- **ARP 패킷**
    - ARP 요청과 응답 과정에서는 ARP 패킷이 전송된다.
    - 프레임의 페이로드에 포함된다.
    - ARP 패킷 형식
        - 오퍼레이션 코드
            - ARP 요청 - 1
            - ARP 응답 - 2
        - 송신지 하드웨어(MAC) 주소
        - 수신지 하드웨어(MAC) 주소
        - 송신지 프로토콜(IP) 주소
        - 수신지 프로토콜(IP) 주소
        
- **다른 네트워크간의 ARP**
    - ARP는 기본적으로 동일 네트워크에서 사용하는 프로토콜
    - 그래서 각 네트워크마다 ARP 요청과 응답을 주고받으며 다른 네트워크의 MAC 주소를 알아내야한다.
    
    ![스크린샷 2025-03-29 오후 11.18.41.jpg](./images/Chapter03/ARP1.jpg)
    
    ![스크린샷 2025-03-29 오후 11.19.07.jpg](./images/Chapter03/ARP2.jpg)
    
</aside>

<aside>

☝️ **IP 단편화는 적게 하는 게 좋다.**

- 적게 해야하는 이유
    - 데이터가 여러 패킷으로 쪼개지면 헤더도 많아지고, 트래픽 증가와 대역폭 낭비로 이어진다.
    - 수신지에서 재조합도 부하를 키운다.
- **IP 단편화를 피하는 방법**
    
    ![스크린샷 2025-03-29 오후 11.16.14.jpg](./images/Chapter03/pathMTU.jpg)
    
    - 경로 MTU 크기 만큼의 데이터를 전송하면 된다.
    - **경로 MTU :** IP 단편화 없이 주고 받을 수 있는 최대 패킷 크기
    - **경로 MTU 발견** : 경로 MTU 찾는 기술
        - 패킷의 DF(Don’t Fragment, 단편화 금지) 플래그를 활성화한다.
        - 만약 어떤 호스트가 처리 불가능한 크기라면 특정 오류 메시지를 전달, 그렇게 데이터 크기를 점차 줄임
</aside>