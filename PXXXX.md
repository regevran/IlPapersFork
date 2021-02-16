---
title: "State Machine"
document: PXXXXR0
date: today
audience:
    - LEWGI
author:
    - name: Ran Regev
      email: <regev.ran@gmail.com>
toc: true
---

# Motivation and Scope
State Machines are fundamental aspect of computer sience and are wildy used in the industry.
There are many aspects to consider when implementing a state machine framwork, and a good standard library can ease the burden for developers.

# Terminology
State Machine means different things to different people.
This sectoin sets the terminology for the rest of the paper.

## FSM
FSM is a Finite State Machine. It encapsulates everything this proposal suggests.<br>
The facility this paper proposed is called fsm.
```cpp
std::fsm my_fsm;
```

## State
A State is ...

## Transition
A Transition is ...

# Types Of State Machines
There are two main types of state machines in use
* "Academic"
* Industrial

## "Academic"
The academic state machine works on its input and stops on a state. The main interest in this type of fsm is its _final state_. By investigating the fsm's final state the user knows the answer to the question being asked.<br>
For example, for words built from the {a,b} alphabiet deciding if a string has odd number of 'a's one can build a fsm that its final state answer this question.<br>
```cpp
bool odd_a(const std::string word) {
    std::fsm my_fsm = /*...*/ // construct the fsm
    for ( char c : word ) {
        my_fsm.fire(c);
    }
    return my_fsm.state() == odd;
}
```

## Industrial
The industrial state machine normally works forever and the main interest is in the behavior in each state regarding the input.<br>
For example, a three tries password access can be moduled with fsm like:
```cpp
    std::fsm::state wait_for_input("wait-for-input");
    std::fsm::state open("open");
    std::fsm::state locked("locked");
    std::fsm::transition(wait_for_input, open, [](const std::string password) -> bool {return password_ok(password);}
    std::fsm::transition(w
```


# Sources
The code for the diagrams in this paper are witten in PlantUML and can be used to regenrate the drawing with uml-generator like https://www.planttext.com

# Acknowledgements
Michael Park <mcpark@gmail.com> (for github.com/mpark/wg21)
