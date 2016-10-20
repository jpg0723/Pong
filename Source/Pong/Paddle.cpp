// Fill out your copyright notice in the Description page of Project Settings.

#include "Pong.h"
#include "Paddle.h"


// Sets default values
APaddle::APaddle()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

}

// Called when the game starts or when spawned
void APaddle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APaddle::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void APaddle::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	// Set up movement bindings
	InputComponent->BindAxis("MoveUp", this, &APaddle::MoveUp);
	InputComponent->BindAxis("MoveRight", this, &APaddle::MoveRight);

}

void APaddle::MoveUp(float Value)
{
	// Find out which direction
	//FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	//this->Jump();
	
	FVector Direction(0, 0, 1);
	AddMovementInput(Direction, Value);

	
}

void APaddle::MoveRight(float Value)
{
	// Find out which direction
	//FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	FVector Direction = FVector::CrossProduct(FVector::UpVector, FVector::ForwardVector);
	AddMovementInput(Direction, Value);
}

