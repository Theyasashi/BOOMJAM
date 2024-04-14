// Fill out your copyright notice in the Description page of Project Settings.
 
 
#include "ObjectWithWorldFromOuter.h"
 
#if WITH_EDITOR
#include "Misc/MessageDialog.h"
#define CHECK_OUTER() \
    do { \
        if (!(GetOuter())) \
        { \
            static bool bWindowShown = false; \
            if (!bWindowShown) \
            { \
                FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(FString::Printf(TEXT("%s 的Outer=nullptr"), *GetFullName()))); \
                bWindowShown = true; \
            } \
        } \
        if (GetOuter() && !GetOuter()->GetWorld()) \
        { \
            static bool bWindowShown = false; \
            if (!bWindowShown) \
            { \
                FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(FString::Printf(TEXT("%s 的Outer GetWorld=nullptr"), *GetOuter()->GetFullName()))); \
                bWindowShown = true; \
            } \
        } \
    } while(0)
#else
#define CHECK_OUTER() do {} while(0)
#endif
 
UWorld* UObjectWithWorldFromOuter::GetWorld() const
{
    if (!HasAnyFlags(RF_ClassDefaultObject))
    {
        CHECK_OUTER();
        if (GetOuter() && !GetOuter()->HasAnyFlags(RF_BeginDestroyed) && !GetOuter()->IsUnreachable())
        {
            return GetOuter()->GetWorld();
        }
    }
    return nullptr;
}