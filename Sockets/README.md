# Sockets

## Problem Solved
Sockets enable network communication between processes, either locally or over networks, supporting various protocols like TCP and UDP.

## What's Good
- Flexible for local and remote communication
- Supports TCP/UDP and other protocols
- Standard interface for network programming

## TCP vs UDP

### When to use TCP:
- **Reliable delivery needed**: TCP guarantees data delivery and order
- **Connection-oriented applications**: Web browsing, file transfer, email
- **Error recovery important**: Automatic retransmission of lost packets
- **Streaming data with guaranteed order**: Video conferencing, database queries

### When to use UDP:
- **Speed over reliability**: Real-time applications like gaming, VoIP
- **Broadcast/multicast**: Sending to multiple recipients
- **Low latency required**: DNS queries, DHCP
- **Small data packets**: NTP, SNMP
- **Custom error handling**: Applications that implement their own reliability

## Better Options
- For local IPC only, use pipes or shared memory for better performance
- For high-level protocols, use libraries like gRPC or HTTP clients
- For message-oriented communication, consider message queues