                                                                                                                                                                             
#________________________________________________________________________________                                                                                                
# DOCKER NETWORK                                                                                                                                                                 
#  SUBNET: "172.18.0.0/16"                                                                                                                                                       
#  GATEWAY: "172.18.0.1"                                                                                                                                                         
#________________________________________________________________________________                                                                                                
network-start:                                                                                                                                                                   
        -docker network create -d bridge ${NETWORK}                                                                                                                              
                                                                                                                                                                                 
network-stop:                                                                                                                                                                    
        -docker network rm ${NETWORK}                                                                                                                                            
                                        