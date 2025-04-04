#include "pch.h"
#include "Output.h"
#include <cstddef>


namespace Server_Library
{
    class Output_Control* Output::control_Of_Output = NULL;
    __int8 Output::out_PraiseEventId = 255;
    class Object* Output::praiseOutputBuffer_Subset = NULL;

    Output::Output()
    {
        praiseOutputBuffer_Subset = NULL;
        out_PraiseEventId = int(255);
    }

    Output::~Output()
    {
        delete control_Of_Output;
        delete praiseOutputBuffer_Subset;
    }

    void Output::Initialise_Control()
    {
        control_Of_Output = new class Server_Library::Output_Control();
        while (control_Of_Output == nullptr) { /* wait untill created */ }
    }

    class Output_Control* Output::Get_Control_Of_Output()
    {
        return control_Of_Output;
    }

    Object* Output::Get_OutputBuffer_Subset()
    {
        return praiseOutputBuffer_Subset;
    }

    __int8 Output::GetPraiseEventId()
    {
        return out_PraiseEventId;
    }

    void Output::Set_OutputBuffer_Subset(class Object* value)
    {
        praiseOutputBuffer_Subset = value;
    }

    void Output::SetPraiseEventId(__int8 value)
    {
        out_PraiseEventId = value;
    }
}
