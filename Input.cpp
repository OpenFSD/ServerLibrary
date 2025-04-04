#include "pch.h"
#include "Input.h"
#include <cstddef>

namespace Server_Library
{
    class Input_Control* Input::input_Control = NULL;
    class Object* Input::buffer_SubSet_InputPraise = NULL;
    __int8 Input::in_praiseEventId = NULL;

    Input::Input()
    {
        input_Control = NULL;
        buffer_SubSet_InputPraise = NULL;
        in_praiseEventId = __int16(0);
    }

    Input::~Input()
    {
        delete input_Control;
        delete buffer_SubSet_InputPraise;
    }

    void Input::Initialise_Control()
    {
        input_Control = new class Server_Library::Input_Control();
        while (input_Control == NULL) { /* wait untill created */ }
    }

    class Input_Control* Input::Get_Input_Control()
    {
        return input_Control;
    }

    __int8 Input::GetPraiseEventId()
    {
        return in_praiseEventId;
    }

    class Object* Input::Get_InputBufferSubset()
    {
        return buffer_SubSet_InputPraise;
    }

    void Input::Set_Subset_InputBuffer(Object* value)
    {
        buffer_SubSet_InputPraise = value;
    }

    void Input::SetPraiseEventId(__int8 value)
    {
        in_praiseEventId = value;
    }
}