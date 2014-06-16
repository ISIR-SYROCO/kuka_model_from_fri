// Filename:  kukaModelFromFri-rtnetcomponent.cpp
// Copyright: 2014 ISIR-CNRS
// Author:  Sovan Hak (hak@isir.upmc.fr) 
// Description:  

#include "kukaModelFromFri-rtnetcomponent.hpp"
#include <rtt/Component.hpp>
#include <iostream>

KukaModelFromFriRTNET::KukaModelFromFriRTNET(std::string const& name) : FriRTNetExampleAbstract(name){
    this->addPort("port_i", port_i);
    this->addPort("port_o", port_o);
}

void KukaModelFromFriRTNET::updateHook(){
   fri_frm_krl = m_fromFRI.get(); 
   if(fri_frm_krl.intData[0] == 1){ //command mode

       RTT::FlowStatus distanceFS = port_distance.read(distance);

       std::vector<double> JState(LWRDOF);

       RTT::FlowStatus joint_state_fs =iport_msr_joint_pos.read(JState);

       if(joint_state_fs == RTT::NewData){
       }
   }

}


/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(Kuka_send_joint_positions)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(KukaModelFromFriRTNET)
