#include "Vector4.h"

#include "Misc/Parse.h"

const FVector4 FVector4::WHITE = { 1.0f, 1.0f, 1.0f, 1.0f };
const FVector4 FVector4::RED = { 1.0f, 0.0f, 0.0f, 1.0f };
const FVector4 FVector4::GREEN = { 0.0f, 1.0f, 0.0f, 1.0f };
const FVector4 FVector4::BLUE = { 0.0f, 0.0f, 1.0f, 1.0f };
const FVector4 FVector4::BLACK = { 0.0f, 0.0f, 0.0f, 1.0f };

// 두 개의 채널이 1인 색상들
const FVector4 FVector4::YELLOW = { 1.0f, 1.0f, 0.0f, 1.0f };    // 빨강 + 초록 = 노랑
const FVector4 FVector4::CYAN = { 0.0f, 1.0f, 1.0f, 1.0f };      // 초록 + 파랑 = 청록색/시안
const FVector4 FVector4::MAGENTA = { 1.0f, 0.0f, 1.0f, 1.0f };   // 빨강 + 파랑 = 자홍색/마젠타

// 추가적인 색상들
const FVector4 FVector4::ORANGE = { 1.0f, 0.5f, 0.0f, 1.0f };    // 주황색
const FVector4 FVector4::PURPLE = { 0.5f, 0.0f, 0.5f, 1.0f };    // 보라색
const FVector4 FVector4::TEAL = { 0.0f, 0.5f, 0.5f, 1.0f };      // 틸(짙은 청록색)

const FVector4 FVector4::ONE = { 1.0f, 1.0f, 1.0f, 1.0f };
const FVector4 FVector4::ONENULL = { 1.0f, 1.0f, 1.0f, 0.0f };
const FVector4 FVector4::ZERO = { 0.0f, 0.0f, 0.0f, 1.0f };
const FVector4 FVector4::ZERONULL = { 0.0f, 0.0f, 0.0f, 0.0f };

const FVector4 FVector4::LEFT = { -1.0f, 0.0f, 0.0f, 0.0f };
const FVector4 FVector4::RIGHT = { 1.0f, 0.0f, 0.0f, 0.0f };
const FVector4 FVector4::UP = { 0.0f, 1.0f, 0.0f, 0.0f };
const FVector4 FVector4::DOWN = { 0.0f, -1.0f, 0.0f, 0.0f };
const FVector4 FVector4::FORWARD = { 0.0f, 0.0f, 1.0f, 0.0f };
const FVector4 FVector4::BACKWARD = { 0.0f, 0.0f, -1.0f, 0.0f };

FVector4 FVector4::MultiplyVector4(const FVector4& a, const FVector4& b)
{
    return FVector4(a.X * b.X, a.Y * b.Y, a.Z * b.Z, a.W * b.W);
}

FVector4 FVector4::VectorMultiplyAdd(const FVector4& A, const FVector4& B, const FVector4& C)
{
    return { A.X * B.X + C.X, A.Y * B.Y + C.Y, A.Z * B.Z + C.Z, A.W * B.W + C.W};
}

FVector4 FVector4::VectorMax(const FVector4& A, const FVector4& B)
{
    return { FMath::Max(A.X, B.X), FMath::Max(A.Y, B.Y), FMath::Max(A.Z, B.Z), FMath::Max(A.W, B.W) };
}	

FString FVector4::ToString() const
{
    // FString::Printf를 사용하여 포맷팅된 문자열 생성
    // TEXT() 매크로는 리터럴 문자열을 TCHAR 타입으로 만들어줍니다.
	return FString::Printf(TEXT("X=%3.3f Y=%3.3f Z=%3.3f W=%3.3f"), X, Y, Z, W);

    // 필요에 따라 소수점 정밀도 지정 가능: 예) "X=%.2f Y=%.2f Z=%.2f"
    // return FString::Printf(TEXT("X=%.2f Y=%.2f Z=%.2f"), x, y, z);
}

bool FVector4::InitFromString(const FString& InSourceString)
{
    X = Y = Z = 0;
    W = 1.0f;

    // The initialization is only successful if the X, Y, and Z values can all be parsed from the string
    const bool bSuccessful = FParse::Value(*InSourceString, TEXT("X=") , X) &&
            FParse::Value(*InSourceString, TEXT("Y="), Y)   &&
            FParse::Value(*InSourceString, TEXT("Z="), Z);

    // W is optional, so don't factor in its presence (or lack thereof) in determining initialization success
    FParse::Value(*InSourceString, TEXT("W="), W);

    return bSuccessful;

}
