# 포켓몬 1~3세대 데이터 헤더

전국도감 **001 이상해씨~386 테오키스**의 기본 폼과 일반 기술 **354개**, 3세대 특성 **76개**, 게임별 습득 기록 **104,243개**를 제공합니다. C++11 이상에서 외부 라이브러리나 실행 시 다운로드 없이 사용할 수 있습니다.

## 파일 구성

- `Types.h`: 타입과 한국어 이름. 3세대 저주의 `???` 타입은 `Type::Unknown`입니다.
- `Models/Enums.h`: 기술 분류, 습득 방식, 게임 버전 열거형.
- `Models/BaseStats.h`, `PokemonInfo.h`, `MoveInfo.h`, `AbilityInfo.h`, `LearnsetEntry.h`, `ArrayView.h`: 각각 독립적인 자료형.
- `Models.h`: 자료형 통합.
- `Species/Generation1.h`, `Generation2.h`, `Generation3.h`: 세대별 포켓몬 기본 정보.
- `Moves/Generation1.h`, `Generation2.h`, `Generation3.h`: 기술의 최초 등장 세대별 목록.
- `Abilities.h`: 특성 번호·한국어 이름·영문 식별자.
- `Learnsets/<게임>/Generation<세대>.h`: 게임 버전과 포켓몬 최초 등장 세대별 습득 기술.
- `Species/All.h`, `Moves/All.h`, `Learnsets/<게임>.h`, `Learnsets/All.h`: 각 범위의 통합 헤더.
- `Lookup/Species.h`, `Moves.h`, `Abilities.h`, `Learnsets.h`: 각 데이터 조회 함수.
- `Lookup.h`, `PokemonData.h`: 전체 조회 기능 통합.
- `Example.cpp`: 현재 프로젝트의 실행 진입점입니다. 다른 수업의 `main()`을 빌드하려면 이 파일을 빌드에서 제외합니다.
- `tools/generate.py`: 원본 CSV를 내려받아 헤더를 재생성하는 도구.
- `tools/validate.cpp`: 데이터 참조, 개수, 역사적 수치 검증.

게임은 적·녹/청 계열(`RedBlue`), 피카츄(`Yellow`), 금·은(`GoldSilver`), 크리스탈(`Crystal`), 루비·사파이어(`RubySapphire`), 에메랄드(`Emerald`), 파이어레드·리프그린(`FireRedLeafGreen`), 콜로세움(`Colosseum`), XD(`Xd`)으로 구분합니다. `RedBlue`는 원본 데이터의 버전 그룹 이름이며 국가별 세부 차이를 따로 표현하지 않습니다.

## 사용법

```cpp
#include "Pokemon/PokemonData.h"

const auto* pokemon = pokemon::FindPokemon(25); // 피카츄
const auto* move = pokemon::FindMove(85);       // 10만볼트
auto entries = pokemon::GetLearnset(25, pokemon::VersionGroup::Emerald);
for (const auto& entry : entries) {
    // entry.moveId, entry.method, entry.level, entry.order
}
bool canLearn = pokemon::CanLearn(25, 85, pokemon::VersionGroup::Emerald);
```

필요한 범위만 포함하려면 예를 들어 `Species/Generation1.h`, `Moves/Generation1.h`, `Learnsets/Emerald/Generation1.h`를 사용합니다. 조회 함수도 해당 `Lookup/` 파일만 포함할 수 있습니다. 배열과 뷰는 읽기 전용이며 수명은 프로그램 전체입니다. 헤더 단독 사용을 위해 배열은 `static const`로 선언되어 여러 번역 단위에서 포함할 경우 복사본이 생길 수 있습니다.

`FindPokemon`, `FindMove`, `FindAbility`는 잘못된 번호에 `nullptr`를 반환합니다. `GetLearnset`은 해당 게임의 해당 포켓몬 습득 기록만 반환하며, 결과가 없으면 빈 뷰입니다. `GetGenerationLearnset(세대, 버전)`으로 해당 포켓몬 세대 전체를 조회할 수도 있습니다.

## 수치와 범위 기준

**포켓몬 기본 정보와 기술의 위력·명중률·PP·타입·분류는 3세대 말 기준**입니다. 1~2세대 포켓몬과 기술도 같은 3세대 전투 규칙에 맞춥니다. 최초 등장 세대로 파일을 나누었으며, 1세대 당시 특수 능력치 통합이나 세대별 전투 규칙 전체를 재현하는 데이터는 아닙니다. 원본의 과거 기록을 적용해 이후 세대의 종족값 상향, 페어리 타입, 추가 특성이 섞이지 않도록 했습니다. 기술 변경 이력도 되돌려 3세대 수치를 사용합니다.

3세대의 물리/특수 분류는 타입에 따라 결정합니다. 노말·격투·비행·독·땅·바위·벌레·고스트·강철은 물리, 나머지 일반 타입은 특수입니다. 변화 기술은 별도로 분류합니다. 예를 들어 섀도볼은 물리, 깨물어부수기는 특수입니다.

기본 정보에는 도감 번호, 한국어 이름, 영문 식별자, 등장 세대, 타입 두 칸, 여섯 종족값, 키(0.1m), 무게(0.1kg), 특성 두 칸이 있습니다. 두 번째 타입/특성이 없으면 각각 `Type::None`/`0`입니다. 숨겨진 특성은 포함하지 않습니다. 테오키스·캐스퐁·안농 등은 도감 번호와 일치하는 기본 폼만 포함하며 게임별/전투 중 폼 변환은 별도 구현해야 합니다.

기술에는 한국어 이름, 위력, PP, 명중률, 우선도, 대상·효과 ID와 효과 발동률을 제공합니다. 원본에서 값이 없는 필드는 `-1`로 보존합니다. 위력 `-1`에는 변화 기술뿐 아니라 고정/가변 피해 기술도 있으므로 `0` 피해로 해석하면 안 됩니다. 명중률 `-1`은 명중 판정 생략을 의미합니다. 효과 ID는 원본 데이터의 참조용이며 실제 기술별 처리 코드는 포함하지 않습니다.

습득 기록은 게임 버전별 레벨업, 교배, 가르침, 기술머신 및 원본의 특수 습득 방식을 보존합니다. 레벨·기술 순서도 저장합니다. `Machine`은 TM/HM을 함께 표현하며 기계 번호 자체는 포함하지 않습니다. `level == 0`은 레벨업 외 방식을 의미하고 `order == -1`은 순서 미지정입니다. GameCube의 다크 기술은 일반 기술 목록과 습득 기록에서 제외합니다. 이벤트 배포·이전 게임에서의 전송·진화 전 단계에서 배운 기술은 자동 합산하지 않습니다. 따라서 `CanLearn`은 해당 종의 직접 습득 기록 존재 여부이며, 현재 레벨·선행 진화·교배 조합·동시 기술 구성의 합법성까지 판정하지 않습니다.

## 출처와 재생성

[PokeAPI 원본 CSV](https://github.com/PokeAPI/pokeapi/tree/master/data/v2/csv) 및 [PokeAPI 데이터 문서](https://pokeapi.co/docs/v2)를 사용했습니다. 사용한 커밋은 `SOURCE_REVISION.txt`에 고정합니다. 포켓몬 관련 이름·데이터의 권리는 원권리자에게 있습니다. 원본 데이터의 누락이나 오기가 있을 수 있으며 이 프로젝트는 공식 데이터 배포물이 아닙니다.

```powershell
python EXTRA_example/Pokemon/tools/generate.py
```

최초 재생성에는 인터넷 연결이 필요합니다. 내려받은 CSV는 `tools/source/`에 캐시되며 Git에서 제외됩니다. 캐시가 있으면 오프라인 재생성이 가능합니다. Python 표준 라이브러리만 사용합니다.

Visual Studio 개발자 명령 프롬프트에서 검증 및 예제 실행:

```bat
cl /nologo /EHsc /std:c++14 /utf-8 EXTRA_example\Pokemon\tools\validate.cpp /Fe:validate.exe
validate.exe
cl /nologo /EHsc /std:c++14 /utf-8 EXTRA_example\Pokemon\Example.cpp /Fe:pokemon-example.exe
chcp 65001
pokemon-example.exe
```

포켓몬·기술·특성 이름은 헤더에서도 읽을 수 있도록 한글 문자열로 직접 저장합니다. 영문 `identifier`는 원본 참조용이며 화면에는 `name`을 출력합니다. 각 포켓몬과 기술은 항목별로 줄을 나누고 한국어 설명을 붙였습니다. 습득 기술표는 포켓몬과 습득 방식별로 묶으며 각 행에 한글 기술명을 표시합니다.

MSVC에서는 `/utf-8`로 컴파일합니다. Visual Studio 프로젝트의 모든 구성에 이 옵션을 추가했습니다. 예제는 Windows 콘솔을 UTF-8로 설정하고 한글 이름·습득 방식을 출력합니다.
