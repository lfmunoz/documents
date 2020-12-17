



HOSTNAME=10.37.120.52                                                                                                                                                            
#HOSTNAME="oc112-22.maas.auslab.2wire.com"                                                                                                                                       
DEBUG_STOMP="-agentlib:jdwp=transport=dt_socket,server=y,address=8000,suspend=n"                                                                                                 
                                                                                                                                                                                 
DEBUG_CONTROL="-agentlib:jdwp=transport=dt_socket,server=y,address=8001,suspend=n"                                                                                               
                                                                                                                                                                                 
JMX_STOMP=-Dcom.sun.management.jmxremote -Dcom.sun.management.jmxremote.port=9100 -Dcom.sun.management.jmxremote.authenticate=false -Dcom.sun.management.jmxremote.ssl=false -Dja
va.rmi.server.hostname=${HOSTNAME}                                                                                                                                               
                                                                                                                                                                                 
JMX_CONTROL=-Dcom.sun.management.jmxremote -Dcom.sun.management.jmxremote.port=9101 -Dcom.sun.management.jmxremote.authenticate=false -Dcom.sun.management.jmxremote.ssl=false -D
java.rmi.server.hostname=${HOSTNAME}                                                                                                                                             
                                                                                                                                                                                 
                                                                                                                                                                                 
HEAP_DUMP=-XX:+HeapDumpOnOutOfMemoryError                                                                                                                                        
MEMORY=-Xmx10G                                                                                                                                                                   
                                                                                                                                                                                 
             