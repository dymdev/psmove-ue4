//
//  FPSMoveWorker.h
//  TestPSMove
//
//  Created by Chadwick Boulay on 2015-02-20.
//  Copyright (c) 2015 EpicGames. All rights reserved.
//
#pragma once

class FPSMoveWorker : public FRunnable
{
public:
    FPSMoveWorker(TArray<FVector>& PSMovePositions, TArray<FQuat>& PSMoveOrientation, TArray<uint32>& PSMoveButtons, TArray<uint32>& PSMovePressed, TArray<uint32>& PSMoveReleased, TArray<uint8>& PSMoveTriggers, TArray<uint8>& PSMoveRumbleRequests); // Usually called by singleton access via Init
    virtual ~FPSMoveWorker(); // Why is this virtual?

    /** Thread for polling the controller and tracker */
    FRunnableThread* Thread;

    /** Ptrs to data containing position and orientation. Will be passed in creator. */
    TArray<FQuat>* WorkerOrientations;
    TArray<FVector>* WorkerPositions;
    TArray<uint32>* WorkerButtons;
    TArray<uint32>* WorkerPressed;
    TArray<uint32>* WorkerReleased;
    TArray<uint8>* WorkerTriggers;
    TArray<uint8>* WorkerRumbleRequests;

    /** Thread Safe Counter. ?? */
    FThreadSafeCounter StopTaskCounter;

    /** FRunnable Interface */
    virtual bool Init(); // override?
    virtual uint32 Run(); // override?
    virtual void Stop(); // override?

    /** Singleton instance for static access. */
    static FPSMoveWorker* WorkerInstance;
    /** Static access to start the thread.*/
    static FPSMoveWorker* PSMoveWorkerInit(TArray<FVector>& PSMovePositions, TArray<FQuat>& PSMoveOrientations, TArray<uint32>& PSMoveButtons, TArray<uint32>& PSMovePressed, TArray<uint32>& PSMoveReleased, TArray<uint8>& PSMoveTriggers, TArray<uint8>& PSMoveRumbleRequests);
    /** Static access to stop the thread.*/
    static void Shutdown();

private:
    /** Objects needed by the Thread
     *  i.e., move_controllers and tracker
     */
    int m_move_count;
    PSMove **m_moves;
    PSMoveTracker *m_tracker;
    float m_tracker_width;
    float m_tracker_height;
};