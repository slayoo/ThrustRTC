﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ThrustRTCLR;
using System.Runtime.InteropServices;

namespace ThrustRTCSharp
{
    public class Functor : DeviceViewable
    {
        static IntPtr create(string[] functor_params, string code_body)
        {
            IntPtr[] p_functor_params = new IntPtr[functor_params.Length];
            for (int i = 0; i< functor_params.Length; i++ )
                p_functor_params[i] = Marshal.StringToHGlobalAnsi(functor_params[i]);

            IntPtr p_code_body = Marshal.StringToHGlobalAnsi(code_body);

            return Native.functor_create(new CapturedDeviceViewable_clr[0], p_functor_params, p_code_body);
        }

        static IntPtr create(DeviceViewable[] objs, string[] name_objs, string[] functor_params, string code_body)
        {
            CapturedDeviceViewable_clr[] arg_map = new CapturedDeviceViewable_clr[objs.Length];
            for (int i = 0; i < objs.Length; i++)
            {
                arg_map[i].obj = objs[i].m_cptr;
                arg_map[i].obj_name = Marshal.StringToHGlobalAnsi(name_objs[i]);
            }

            IntPtr[] p_functor_params = new IntPtr[functor_params.Length];
            for (int i = 0; i < functor_params.Length; i++)
                p_functor_params[i] = Marshal.StringToHGlobalAnsi(functor_params[i]);

            IntPtr p_code_body = Marshal.StringToHGlobalAnsi(code_body);

            return Native.functor_create(arg_map, p_functor_params, p_code_body);
        }
  
        public Functor(string[] functor_params, string code_body) 
            : base(create(functor_params, code_body)) {}

        public Functor(DeviceViewable[] objs, string[] name_objs, string[] functor_params, string code_body)
            : base(create(objs, name_objs, functor_params, code_body)) { }

        public Functor(String name_built_in_view_cls)
            : base(Native.built_in_functor_create(Marshal.StringToHGlobalAnsi(name_built_in_view_cls))) { }

    }
}
