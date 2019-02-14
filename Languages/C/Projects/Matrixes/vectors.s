
vectors:     file format elf64-x86-64


Disassembly of section .init:

00000000004005e8 <_init>:
  4005e8:	48 83 ec 08          	sub    $0x8,%rsp
  4005ec:	48 8b 05 05 2a 20 00 	mov    0x202a05(%rip),%rax        # 602ff8 <_DYNAMIC+0x1d0>
  4005f3:	48 85 c0             	test   %rax,%rax
  4005f6:	74 05                	je     4005fd <_init+0x15>
  4005f8:	e8 c3 00 00 00       	callq  4006c0 <fwrite@plt+0x10>
  4005fd:	48 83 c4 08          	add    $0x8,%rsp
  400601:	c3                   	retq   

Disassembly of section .plt:

0000000000400610 <free@plt-0x10>:
  400610:	ff 35 f2 29 20 00    	pushq  0x2029f2(%rip)        # 603008 <_GLOBAL_OFFSET_TABLE_+0x8>
  400616:	ff 25 f4 29 20 00    	jmpq   *0x2029f4(%rip)        # 603010 <_GLOBAL_OFFSET_TABLE_+0x10>
  40061c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400620 <free@plt>:
  400620:	ff 25 f2 29 20 00    	jmpq   *0x2029f2(%rip)        # 603018 <_GLOBAL_OFFSET_TABLE_+0x18>
  400626:	68 00 00 00 00       	pushq  $0x0
  40062b:	e9 e0 ff ff ff       	jmpq   400610 <_init+0x28>

0000000000400630 <puts@plt>:
  400630:	ff 25 ea 29 20 00    	jmpq   *0x2029ea(%rip)        # 603020 <_GLOBAL_OFFSET_TABLE_+0x20>
  400636:	68 01 00 00 00       	pushq  $0x1
  40063b:	e9 d0 ff ff ff       	jmpq   400610 <_init+0x28>

0000000000400640 <__stack_chk_fail@plt>:
  400640:	ff 25 e2 29 20 00    	jmpq   *0x2029e2(%rip)        # 603028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400646:	68 02 00 00 00       	pushq  $0x2
  40064b:	e9 c0 ff ff ff       	jmpq   400610 <_init+0x28>

0000000000400650 <printf@plt>:
  400650:	ff 25 da 29 20 00    	jmpq   *0x2029da(%rip)        # 603030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400656:	68 03 00 00 00       	pushq  $0x3
  40065b:	e9 b0 ff ff ff       	jmpq   400610 <_init+0x28>

0000000000400660 <__libc_start_main@plt>:
  400660:	ff 25 d2 29 20 00    	jmpq   *0x2029d2(%rip)        # 603038 <_GLOBAL_OFFSET_TABLE_+0x38>
  400666:	68 04 00 00 00       	pushq  $0x4
  40066b:	e9 a0 ff ff ff       	jmpq   400610 <_init+0x28>

0000000000400670 <calloc@plt>:
  400670:	ff 25 ca 29 20 00    	jmpq   *0x2029ca(%rip)        # 603040 <_GLOBAL_OFFSET_TABLE_+0x40>
  400676:	68 05 00 00 00       	pushq  $0x5
  40067b:	e9 90 ff ff ff       	jmpq   400610 <_init+0x28>

0000000000400680 <fprintf@plt>:
  400680:	ff 25 c2 29 20 00    	jmpq   *0x2029c2(%rip)        # 603048 <_GLOBAL_OFFSET_TABLE_+0x48>
  400686:	68 06 00 00 00       	pushq  $0x6
  40068b:	e9 80 ff ff ff       	jmpq   400610 <_init+0x28>

0000000000400690 <malloc@plt>:
  400690:	ff 25 ba 29 20 00    	jmpq   *0x2029ba(%rip)        # 603050 <_GLOBAL_OFFSET_TABLE_+0x50>
  400696:	68 07 00 00 00       	pushq  $0x7
  40069b:	e9 70 ff ff ff       	jmpq   400610 <_init+0x28>

00000000004006a0 <exit@plt>:
  4006a0:	ff 25 b2 29 20 00    	jmpq   *0x2029b2(%rip)        # 603058 <_GLOBAL_OFFSET_TABLE_+0x58>
  4006a6:	68 08 00 00 00       	pushq  $0x8
  4006ab:	e9 60 ff ff ff       	jmpq   400610 <_init+0x28>

00000000004006b0 <fwrite@plt>:
  4006b0:	ff 25 aa 29 20 00    	jmpq   *0x2029aa(%rip)        # 603060 <_GLOBAL_OFFSET_TABLE_+0x60>
  4006b6:	68 09 00 00 00       	pushq  $0x9
  4006bb:	e9 50 ff ff ff       	jmpq   400610 <_init+0x28>

Disassembly of section .plt.got:

00000000004006c0 <.plt.got>:
  4006c0:	ff 25 32 29 20 00    	jmpq   *0x202932(%rip)        # 602ff8 <_DYNAMIC+0x1d0>
  4006c6:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

00000000004006d0 <_start>:
  4006d0:	31 ed                	xor    %ebp,%ebp
  4006d2:	49 89 d1             	mov    %rdx,%r9
  4006d5:	5e                   	pop    %rsi
  4006d6:	48 89 e2             	mov    %rsp,%rdx
  4006d9:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  4006dd:	50                   	push   %rax
  4006de:	54                   	push   %rsp
  4006df:	49 c7 c0 50 21 40 00 	mov    $0x402150,%r8
  4006e6:	48 c7 c1 e0 20 40 00 	mov    $0x4020e0,%rcx
  4006ed:	48 c7 c7 c6 07 40 00 	mov    $0x4007c6,%rdi
  4006f4:	e8 67 ff ff ff       	callq  400660 <__libc_start_main@plt>
  4006f9:	f4                   	hlt    
  4006fa:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400700 <deregister_tm_clones>:
  400700:	b8 7f 30 60 00       	mov    $0x60307f,%eax
  400705:	55                   	push   %rbp
  400706:	48 2d 78 30 60 00    	sub    $0x603078,%rax
  40070c:	48 83 f8 0e          	cmp    $0xe,%rax
  400710:	48 89 e5             	mov    %rsp,%rbp
  400713:	76 1b                	jbe    400730 <deregister_tm_clones+0x30>
  400715:	b8 00 00 00 00       	mov    $0x0,%eax
  40071a:	48 85 c0             	test   %rax,%rax
  40071d:	74 11                	je     400730 <deregister_tm_clones+0x30>
  40071f:	5d                   	pop    %rbp
  400720:	bf 78 30 60 00       	mov    $0x603078,%edi
  400725:	ff e0                	jmpq   *%rax
  400727:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  40072e:	00 00 
  400730:	5d                   	pop    %rbp
  400731:	c3                   	retq   
  400732:	0f 1f 40 00          	nopl   0x0(%rax)
  400736:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40073d:	00 00 00 

0000000000400740 <register_tm_clones>:
  400740:	be 78 30 60 00       	mov    $0x603078,%esi
  400745:	55                   	push   %rbp
  400746:	48 81 ee 78 30 60 00 	sub    $0x603078,%rsi
  40074d:	48 c1 fe 03          	sar    $0x3,%rsi
  400751:	48 89 e5             	mov    %rsp,%rbp
  400754:	48 89 f0             	mov    %rsi,%rax
  400757:	48 c1 e8 3f          	shr    $0x3f,%rax
  40075b:	48 01 c6             	add    %rax,%rsi
  40075e:	48 d1 fe             	sar    %rsi
  400761:	74 15                	je     400778 <register_tm_clones+0x38>
  400763:	b8 00 00 00 00       	mov    $0x0,%eax
  400768:	48 85 c0             	test   %rax,%rax
  40076b:	74 0b                	je     400778 <register_tm_clones+0x38>
  40076d:	5d                   	pop    %rbp
  40076e:	bf 78 30 60 00       	mov    $0x603078,%edi
  400773:	ff e0                	jmpq   *%rax
  400775:	0f 1f 00             	nopl   (%rax)
  400778:	5d                   	pop    %rbp
  400779:	c3                   	retq   
  40077a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400780 <__do_global_dtors_aux>:
  400780:	80 3d 01 29 20 00 00 	cmpb   $0x0,0x202901(%rip)        # 603088 <completed.7585>
  400787:	75 11                	jne    40079a <__do_global_dtors_aux+0x1a>
  400789:	55                   	push   %rbp
  40078a:	48 89 e5             	mov    %rsp,%rbp
  40078d:	e8 6e ff ff ff       	callq  400700 <deregister_tm_clones>
  400792:	5d                   	pop    %rbp
  400793:	c6 05 ee 28 20 00 01 	movb   $0x1,0x2028ee(%rip)        # 603088 <completed.7585>
  40079a:	f3 c3                	repz retq 
  40079c:	0f 1f 40 00          	nopl   0x0(%rax)

00000000004007a0 <frame_dummy>:
  4007a0:	bf 20 2e 60 00       	mov    $0x602e20,%edi
  4007a5:	48 83 3f 00          	cmpq   $0x0,(%rdi)
  4007a9:	75 05                	jne    4007b0 <frame_dummy+0x10>
  4007ab:	eb 93                	jmp    400740 <register_tm_clones>
  4007ad:	0f 1f 00             	nopl   (%rax)
  4007b0:	b8 00 00 00 00       	mov    $0x0,%eax
  4007b5:	48 85 c0             	test   %rax,%rax
  4007b8:	74 f1                	je     4007ab <frame_dummy+0xb>
  4007ba:	55                   	push   %rbp
  4007bb:	48 89 e5             	mov    %rsp,%rbp
  4007be:	ff d0                	callq  *%rax
  4007c0:	5d                   	pop    %rbp
  4007c1:	e9 7a ff ff ff       	jmpq   400740 <register_tm_clones>

00000000004007c6 <main>:
  4007c6:	55                   	push   %rbp
  4007c7:	48 89 e5             	mov    %rsp,%rbp
  4007ca:	48 81 ec 20 01 00 00 	sub    $0x120,%rsp
  4007d1:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  4007d8:	00 00 
  4007da:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  4007de:	31 c0                	xor    %eax,%eax
  4007e0:	bf 68 21 40 00       	mov    $0x402168,%edi
  4007e5:	e8 46 fe ff ff       	callq  400630 <puts@plt>
  4007ea:	f3 0f 10 05 96 1a 00 	movss  0x1a96(%rip),%xmm0        # 402288 <_IO_stdin_used+0x128>
  4007f1:	00 
  4007f2:	f3 0f 11 45 b0       	movss  %xmm0,-0x50(%rbp)
  4007f7:	f3 0f 10 05 8d 1a 00 	movss  0x1a8d(%rip),%xmm0        # 40228c <_IO_stdin_used+0x12c>
  4007fe:	00 
  4007ff:	f3 0f 11 45 b4       	movss  %xmm0,-0x4c(%rbp)
  400804:	f3 0f 10 05 84 1a 00 	movss  0x1a84(%rip),%xmm0        # 402290 <_IO_stdin_used+0x130>
  40080b:	00 
  40080c:	f3 0f 11 45 b8       	movss  %xmm0,-0x48(%rbp)
  400811:	66 0f ef c0          	pxor   %xmm0,%xmm0
  400815:	f3 0f 11 45 bc       	movss  %xmm0,-0x44(%rbp)
  40081a:	f3 0f 10 05 72 1a 00 	movss  0x1a72(%rip),%xmm0        # 402294 <_IO_stdin_used+0x134>
  400821:	00 
  400822:	f3 0f 11 45 c0       	movss  %xmm0,-0x40(%rbp)
  400827:	f3 0f 10 05 69 1a 00 	movss  0x1a69(%rip),%xmm0        # 402298 <_IO_stdin_used+0x138>
  40082e:	00 
  40082f:	f3 0f 11 45 c4       	movss  %xmm0,-0x3c(%rbp)
  400834:	f3 0f 10 05 60 1a 00 	movss  0x1a60(%rip),%xmm0        # 40229c <_IO_stdin_used+0x13c>
  40083b:	00 
  40083c:	f3 0f 11 45 c8       	movss  %xmm0,-0x38(%rbp)
  400841:	f3 0f 10 05 47 1a 00 	movss  0x1a47(%rip),%xmm0        # 402290 <_IO_stdin_used+0x130>
  400848:	00 
  400849:	f3 0f 11 45 cc       	movss  %xmm0,-0x34(%rbp)
  40084e:	f3 0f 10 05 36 1a 00 	movss  0x1a36(%rip),%xmm0        # 40228c <_IO_stdin_used+0x12c>
  400855:	00 
  400856:	f3 0f 11 45 d0       	movss  %xmm0,-0x30(%rbp)
  40085b:	f3 0f 10 05 31 1a 00 	movss  0x1a31(%rip),%xmm0        # 402294 <_IO_stdin_used+0x134>
  400862:	00 
  400863:	f3 0f 11 45 d4       	movss  %xmm0,-0x2c(%rbp)
  400868:	f3 0f 10 05 20 1a 00 	movss  0x1a20(%rip),%xmm0        # 402290 <_IO_stdin_used+0x130>
  40086f:	00 
  400870:	f3 0f 11 45 d8       	movss  %xmm0,-0x28(%rbp)
  400875:	f3 0f 10 05 23 1a 00 	movss  0x1a23(%rip),%xmm0        # 4022a0 <_IO_stdin_used+0x140>
  40087c:	00 
  40087d:	f3 0f 11 45 dc       	movss  %xmm0,-0x24(%rbp)
  400882:	f3 0f 10 05 1a 1a 00 	movss  0x1a1a(%rip),%xmm0        # 4022a4 <_IO_stdin_used+0x144>
  400889:	00 
  40088a:	f3 0f 11 45 e0       	movss  %xmm0,-0x20(%rbp)
  40088f:	f3 0f 10 05 f9 19 00 	movss  0x19f9(%rip),%xmm0        # 402290 <_IO_stdin_used+0x130>
  400896:	00 
  400897:	f3 0f 11 45 e4       	movss  %xmm0,-0x1c(%rbp)
  40089c:	f3 0f 10 05 04 1a 00 	movss  0x1a04(%rip),%xmm0        # 4022a8 <_IO_stdin_used+0x148>
  4008a3:	00 
  4008a4:	f3 0f 11 45 e8       	movss  %xmm0,-0x18(%rbp)
  4008a9:	f3 0f 10 05 fb 19 00 	movss  0x19fb(%rip),%xmm0        # 4022ac <_IO_stdin_used+0x14c>
  4008b0:	00 
  4008b1:	f3 0f 11 45 ec       	movss  %xmm0,-0x14(%rbp)
  4008b6:	be 04 00 00 00       	mov    $0x4,%esi
  4008bb:	bf 04 00 00 00       	mov    $0x4,%edi
  4008c0:	e8 5e 0e 00 00       	callq  401723 <createMatrix>
  4008c5:	48 89 85 e8 fe ff ff 	mov    %rax,-0x118(%rbp)
  4008cc:	48 8d 55 b0          	lea    -0x50(%rbp),%rdx
  4008d0:	48 8b 85 e8 fe ff ff 	mov    -0x118(%rbp),%rax
  4008d7:	48 89 d1             	mov    %rdx,%rcx
  4008da:	ba 04 00 00 00       	mov    $0x4,%edx
  4008df:	be 04 00 00 00       	mov    $0x4,%esi
  4008e4:	48 89 c7             	mov    %rax,%rdi
  4008e7:	e8 dc 0e 00 00       	callq  4017c8 <copyMatrix>
  4008ec:	48 8b 85 e8 fe ff ff 	mov    -0x118(%rbp),%rax
  4008f3:	48 89 c7             	mov    %rax,%rdi
  4008f6:	e8 5f 12 00 00       	callq  401b5a <showMatrix>
  4008fb:	48 8b 85 e8 fe ff ff 	mov    -0x118(%rbp),%rax
  400902:	48 89 c7             	mov    %rax,%rdi
  400905:	e8 dc 13 00 00       	callq  401ce6 <findDeterminant>
  40090a:	66 0f ef c0          	pxor   %xmm0,%xmm0
  40090e:	f3 0f 2a c0          	cvtsi2ss %eax,%xmm0
  400912:	f3 0f 11 85 e4 fe ff 	movss  %xmm0,-0x11c(%rbp)
  400919:	ff 
  40091a:	f3 0f 5a 85 e4 fe ff 	cvtss2sd -0x11c(%rbp),%xmm0
  400921:	ff 
  400922:	bf 77 21 40 00       	mov    $0x402177,%edi
  400927:	b8 01 00 00 00       	mov    $0x1,%eax
  40092c:	e8 1f fd ff ff       	callq  400650 <printf@plt>
  400931:	bf 95 21 40 00       	mov    $0x402195,%edi
  400936:	e8 f5 fc ff ff       	callq  400630 <puts@plt>
  40093b:	f3 0f 10 05 69 19 00 	movss  0x1969(%rip),%xmm0        # 4022ac <_IO_stdin_used+0x14c>
  400942:	00 
  400943:	f3 0f 11 85 60 ff ff 	movss  %xmm0,-0xa0(%rbp)
  40094a:	ff 
  40094b:	f3 0f 10 05 3d 19 00 	movss  0x193d(%rip),%xmm0        # 402290 <_IO_stdin_used+0x130>
  400952:	00 
  400953:	f3 0f 11 85 64 ff ff 	movss  %xmm0,-0x9c(%rbp)
  40095a:	ff 
  40095b:	f3 0f 10 05 3d 19 00 	movss  0x193d(%rip),%xmm0        # 4022a0 <_IO_stdin_used+0x140>
  400962:	00 
  400963:	f3 0f 11 85 68 ff ff 	movss  %xmm0,-0x98(%rbp)
  40096a:	ff 
  40096b:	f3 0f 10 05 21 19 00 	movss  0x1921(%rip),%xmm0        # 402294 <_IO_stdin_used+0x134>
  400972:	00 
  400973:	f3 0f 11 85 6c ff ff 	movss  %xmm0,-0x94(%rbp)
  40097a:	ff 
  40097b:	f3 0f 10 05 05 19 00 	movss  0x1905(%rip),%xmm0        # 402288 <_IO_stdin_used+0x128>
  400982:	00 
  400983:	f3 0f 11 85 70 ff ff 	movss  %xmm0,-0x90(%rbp)
  40098a:	ff 
  40098b:	f3 0f 10 05 11 19 00 	movss  0x1911(%rip),%xmm0        # 4022a4 <_IO_stdin_used+0x144>
  400992:	00 
  400993:	f3 0f 11 85 74 ff ff 	movss  %xmm0,-0x8c(%rbp)
  40099a:	ff 
  40099b:	f3 0f 10 05 0d 19 00 	movss  0x190d(%rip),%xmm0        # 4022b0 <_IO_stdin_used+0x150>
  4009a2:	00 
  4009a3:	f3 0f 11 85 78 ff ff 	movss  %xmm0,-0x88(%rbp)
  4009aa:	ff 
  4009ab:	f3 0f 10 05 ed 18 00 	movss  0x18ed(%rip),%xmm0        # 4022a0 <_IO_stdin_used+0x140>
  4009b2:	00 
  4009b3:	f3 0f 11 85 7c ff ff 	movss  %xmm0,-0x84(%rbp)
  4009ba:	ff 
  4009bb:	be 02 00 00 00       	mov    $0x2,%esi
  4009c0:	bf 04 00 00 00       	mov    $0x4,%edi
  4009c5:	e8 59 0d 00 00       	callq  401723 <createMatrix>
  4009ca:	48 89 85 f0 fe ff ff 	mov    %rax,-0x110(%rbp)
  4009d1:	48 8d 95 60 ff ff ff 	lea    -0xa0(%rbp),%rdx
  4009d8:	48 8b 85 f0 fe ff ff 	mov    -0x110(%rbp),%rax
  4009df:	48 89 d1             	mov    %rdx,%rcx
  4009e2:	ba 02 00 00 00       	mov    $0x2,%edx
  4009e7:	be 04 00 00 00       	mov    $0x4,%esi
  4009ec:	48 89 c7             	mov    %rax,%rdi
  4009ef:	e8 d4 0d 00 00       	callq  4017c8 <copyMatrix>
  4009f4:	48 8b 85 f0 fe ff ff 	mov    -0x110(%rbp),%rax
  4009fb:	48 89 c7             	mov    %rax,%rdi
  4009fe:	e8 57 11 00 00       	callq  401b5a <showMatrix>
  400a03:	bf a4 21 40 00       	mov    $0x4021a4,%edi
  400a08:	e8 23 fc ff ff       	callq  400630 <puts@plt>
  400a0d:	48 8b 95 f0 fe ff ff 	mov    -0x110(%rbp),%rdx
  400a14:	48 8b 85 e8 fe ff ff 	mov    -0x118(%rbp),%rax
  400a1b:	48 89 d6             	mov    %rdx,%rsi
  400a1e:	48 89 c7             	mov    %rax,%rdi
  400a21:	e8 dc 14 00 00       	callq  401f02 <multiplyMatrix>
  400a26:	48 89 85 f8 fe ff ff 	mov    %rax,-0x108(%rbp)
  400a2d:	48 8b 85 f8 fe ff ff 	mov    -0x108(%rbp),%rax
  400a34:	48 89 c7             	mov    %rax,%rdi
  400a37:	e8 1e 11 00 00       	callq  401b5a <showMatrix>
  400a3c:	bf ae 21 40 00       	mov    $0x4021ae,%edi
  400a41:	e8 ea fb ff ff       	callq  400630 <puts@plt>
  400a46:	be 03 00 00 00       	mov    $0x3,%esi
  400a4b:	bf 03 00 00 00       	mov    $0x3,%edi
  400a50:	e8 ce 0c 00 00       	callq  401723 <createMatrix>
  400a55:	48 89 85 00 ff ff ff 	mov    %rax,-0x100(%rbp)
  400a5c:	f3 0f 10 05 38 18 00 	movss  0x1838(%rip),%xmm0        # 40229c <_IO_stdin_used+0x13c>
  400a63:	00 
  400a64:	f3 0f 11 45 80       	movss  %xmm0,-0x80(%rbp)
  400a69:	f3 0f 10 05 1f 18 00 	movss  0x181f(%rip),%xmm0        # 402290 <_IO_stdin_used+0x130>
  400a70:	00 
  400a71:	f3 0f 11 45 84       	movss  %xmm0,-0x7c(%rbp)
  400a76:	f3 0f 10 05 2e 18 00 	movss  0x182e(%rip),%xmm0        # 4022ac <_IO_stdin_used+0x14c>
  400a7d:	00 
  400a7e:	f3 0f 11 45 88       	movss  %xmm0,-0x78(%rbp)
  400a83:	f3 0f 10 05 21 18 00 	movss  0x1821(%rip),%xmm0        # 4022ac <_IO_stdin_used+0x14c>
  400a8a:	00 
  400a8b:	f3 0f 11 45 8c       	movss  %xmm0,-0x74(%rbp)
  400a90:	f3 0f 10 05 04 18 00 	movss  0x1804(%rip),%xmm0        # 40229c <_IO_stdin_used+0x13c>
  400a97:	00 
  400a98:	f3 0f 11 45 90       	movss  %xmm0,-0x70(%rbp)
  400a9d:	66 0f ef c0          	pxor   %xmm0,%xmm0
  400aa1:	f3 0f 11 45 94       	movss  %xmm0,-0x6c(%rbp)
  400aa6:	f3 0f 10 05 ea 17 00 	movss  0x17ea(%rip),%xmm0        # 402298 <_IO_stdin_used+0x138>
  400aad:	00 
  400aae:	f3 0f 11 45 98       	movss  %xmm0,-0x68(%rbp)
  400ab3:	f3 0f 10 05 f9 17 00 	movss  0x17f9(%rip),%xmm0        # 4022b4 <_IO_stdin_used+0x154>
  400aba:	00 
  400abb:	f3 0f 11 45 9c       	movss  %xmm0,-0x64(%rbp)
  400ac0:	f3 0f 10 05 e4 17 00 	movss  0x17e4(%rip),%xmm0        # 4022ac <_IO_stdin_used+0x14c>
  400ac7:	00 
  400ac8:	f3 0f 11 45 a0       	movss  %xmm0,-0x60(%rbp)
  400acd:	48 8d 55 80          	lea    -0x80(%rbp),%rdx
  400ad1:	48 8b 85 00 ff ff ff 	mov    -0x100(%rbp),%rax
  400ad8:	48 89 d1             	mov    %rdx,%rcx
  400adb:	ba 03 00 00 00       	mov    $0x3,%edx
  400ae0:	be 03 00 00 00       	mov    $0x3,%esi
  400ae5:	48 89 c7             	mov    %rax,%rdi
  400ae8:	e8 db 0c 00 00       	callq  4017c8 <copyMatrix>
  400aed:	48 8b 85 00 ff ff ff 	mov    -0x100(%rbp),%rax
  400af4:	48 89 c7             	mov    %rax,%rdi
  400af7:	e8 5e 10 00 00       	callq  401b5a <showMatrix>
  400afc:	bf bd 21 40 00       	mov    $0x4021bd,%edi
  400b01:	e8 2a fb ff ff       	callq  400630 <puts@plt>
  400b06:	be 01 00 00 00       	mov    $0x1,%esi
  400b0b:	bf 03 00 00 00       	mov    $0x3,%edi
  400b10:	e8 0e 0c 00 00       	callq  401723 <createMatrix>
  400b15:	48 89 85 08 ff ff ff 	mov    %rax,-0xf8(%rbp)
  400b1c:	f3 0f 10 05 68 17 00 	movss  0x1768(%rip),%xmm0        # 40228c <_IO_stdin_used+0x12c>
  400b23:	00 
  400b24:	f3 0f 11 85 30 ff ff 	movss  %xmm0,-0xd0(%rbp)
  400b2b:	ff 
  400b2c:	f3 0f 10 05 78 17 00 	movss  0x1778(%rip),%xmm0        # 4022ac <_IO_stdin_used+0x14c>
  400b33:	00 
  400b34:	f3 0f 11 85 34 ff ff 	movss  %xmm0,-0xcc(%rbp)
  400b3b:	ff 
  400b3c:	f3 0f 10 05 60 17 00 	movss  0x1760(%rip),%xmm0        # 4022a4 <_IO_stdin_used+0x144>
  400b43:	00 
  400b44:	f3 0f 11 85 38 ff ff 	movss  %xmm0,-0xc8(%rbp)
  400b4b:	ff 
  400b4c:	48 8d 95 30 ff ff ff 	lea    -0xd0(%rbp),%rdx
  400b53:	48 8b 85 08 ff ff ff 	mov    -0xf8(%rbp),%rax
  400b5a:	48 89 d1             	mov    %rdx,%rcx
  400b5d:	ba 01 00 00 00       	mov    $0x1,%edx
  400b62:	be 03 00 00 00       	mov    $0x3,%esi
  400b67:	48 89 c7             	mov    %rax,%rdi
  400b6a:	e8 59 0c 00 00       	callq  4017c8 <copyMatrix>
  400b6f:	48 8b 85 08 ff ff ff 	mov    -0xf8(%rbp),%rax
  400b76:	48 89 c7             	mov    %rax,%rdi
  400b79:	e8 dc 0f 00 00       	callq  401b5a <showMatrix>
  400b7e:	bf cc 21 40 00       	mov    $0x4021cc,%edi
  400b83:	e8 a8 fa ff ff       	callq  400630 <puts@plt>
  400b88:	48 8b 95 08 ff ff ff 	mov    -0xf8(%rbp),%rdx
  400b8f:	48 8b 85 00 ff ff ff 	mov    -0x100(%rbp),%rax
  400b96:	48 89 d6             	mov    %rdx,%rsi
  400b99:	48 89 c7             	mov    %rax,%rdi
  400b9c:	e8 5d 02 00 00       	callq  400dfe <createAugMatrix>
  400ba1:	48 89 85 10 ff ff ff 	mov    %rax,-0xf0(%rbp)
  400ba8:	48 8b 85 10 ff ff ff 	mov    -0xf0(%rbp),%rax
  400baf:	48 89 c7             	mov    %rax,%rdi
  400bb2:	e8 a3 0f 00 00       	callq  401b5a <showMatrix>
  400bb7:	bf f0 21 40 00       	mov    $0x4021f0,%edi
  400bbc:	e8 6f fa ff ff       	callq  400630 <puts@plt>
  400bc1:	48 8b 85 10 ff ff ff 	mov    -0xf0(%rbp),%rax
  400bc8:	48 89 c7             	mov    %rax,%rdi
  400bcb:	e8 5d 08 00 00       	callq  40142d <reduceMatrix>
  400bd0:	48 8b 85 10 ff ff ff 	mov    -0xf0(%rbp),%rax
  400bd7:	48 89 c7             	mov    %rax,%rdi
  400bda:	e8 7b 0f 00 00       	callq  401b5a <showMatrix>
  400bdf:	bf 11 22 40 00       	mov    $0x402211,%edi
  400be4:	e8 47 fa ff ff       	callq  400630 <puts@plt>
  400be9:	be 02 00 00 00       	mov    $0x2,%esi
  400bee:	bf 02 00 00 00       	mov    $0x2,%edi
  400bf3:	e8 2b 0b 00 00       	callq  401723 <createMatrix>
  400bf8:	48 89 85 18 ff ff ff 	mov    %rax,-0xe8(%rbp)
  400bff:	f3 0f 10 05 a5 16 00 	movss  0x16a5(%rip),%xmm0        # 4022ac <_IO_stdin_used+0x14c>
  400c06:	00 
  400c07:	f3 0f 11 85 40 ff ff 	movss  %xmm0,-0xc0(%rbp)
  400c0e:	ff 
  400c0f:	66 0f ef c0          	pxor   %xmm0,%xmm0
  400c13:	f3 0f 11 85 44 ff ff 	movss  %xmm0,-0xbc(%rbp)
  400c1a:	ff 
  400c1b:	66 0f ef c0          	pxor   %xmm0,%xmm0
  400c1f:	f3 0f 11 85 48 ff ff 	movss  %xmm0,-0xb8(%rbp)
  400c26:	ff 
  400c27:	f3 0f 10 05 7d 16 00 	movss  0x167d(%rip),%xmm0        # 4022ac <_IO_stdin_used+0x14c>
  400c2e:	00 
  400c2f:	f3 0f 11 85 4c ff ff 	movss  %xmm0,-0xb4(%rbp)
  400c36:	ff 
  400c37:	48 8d 95 40 ff ff ff 	lea    -0xc0(%rbp),%rdx
  400c3e:	48 8b 85 18 ff ff ff 	mov    -0xe8(%rbp),%rax
  400c45:	48 89 d1             	mov    %rdx,%rcx
  400c48:	ba 02 00 00 00       	mov    $0x2,%edx
  400c4d:	be 02 00 00 00       	mov    $0x2,%esi
  400c52:	48 89 c7             	mov    %rax,%rdi
  400c55:	e8 6e 0b 00 00       	callq  4017c8 <copyMatrix>
  400c5a:	48 8b 85 18 ff ff ff 	mov    -0xe8(%rbp),%rax
  400c61:	48 89 c7             	mov    %rax,%rdi
  400c64:	e8 f1 0e 00 00       	callq  401b5a <showMatrix>
  400c69:	bf 2b 22 40 00       	mov    $0x40222b,%edi
  400c6e:	e8 bd f9 ff ff       	callq  400630 <puts@plt>
  400c73:	be 02 00 00 00       	mov    $0x2,%esi
  400c78:	bf 02 00 00 00       	mov    $0x2,%edi
  400c7d:	e8 a1 0a 00 00       	callq  401723 <createMatrix>
  400c82:	48 89 85 20 ff ff ff 	mov    %rax,-0xe0(%rbp)
  400c89:	f3 0f 10 05 07 16 00 	movss  0x1607(%rip),%xmm0        # 402298 <_IO_stdin_used+0x138>
  400c90:	00 
  400c91:	f3 0f 11 85 50 ff ff 	movss  %xmm0,-0xb0(%rbp)
  400c98:	ff 
  400c99:	f3 0f 10 05 17 16 00 	movss  0x1617(%rip),%xmm0        # 4022b8 <_IO_stdin_used+0x158>
  400ca0:	00 
  400ca1:	f3 0f 11 85 54 ff ff 	movss  %xmm0,-0xac(%rbp)
  400ca8:	ff 
  400ca9:	f3 0f 10 05 0b 16 00 	movss  0x160b(%rip),%xmm0        # 4022bc <_IO_stdin_used+0x15c>
  400cb0:	00 
  400cb1:	f3 0f 11 85 58 ff ff 	movss  %xmm0,-0xa8(%rbp)
  400cb8:	ff 
  400cb9:	f3 0f 10 05 ff 15 00 	movss  0x15ff(%rip),%xmm0        # 4022c0 <_IO_stdin_used+0x160>
  400cc0:	00 
  400cc1:	f3 0f 11 85 5c ff ff 	movss  %xmm0,-0xa4(%rbp)
  400cc8:	ff 
  400cc9:	48 8d 95 50 ff ff ff 	lea    -0xb0(%rbp),%rdx
  400cd0:	48 8b 85 20 ff ff ff 	mov    -0xe0(%rbp),%rax
  400cd7:	48 89 d1             	mov    %rdx,%rcx
  400cda:	ba 02 00 00 00       	mov    $0x2,%edx
  400cdf:	be 02 00 00 00       	mov    $0x2,%esi
  400ce4:	48 89 c7             	mov    %rax,%rdi
  400ce7:	e8 dc 0a 00 00       	callq  4017c8 <copyMatrix>
  400cec:	48 8b 85 20 ff ff ff 	mov    -0xe0(%rbp),%rax
  400cf3:	48 89 c7             	mov    %rax,%rdi
  400cf6:	e8 5f 0e 00 00       	callq  401b5a <showMatrix>
  400cfb:	bf 48 22 40 00       	mov    $0x402248,%edi
  400d00:	e8 2b f9 ff ff       	callq  400630 <puts@plt>
  400d05:	48 8b 95 18 ff ff ff 	mov    -0xe8(%rbp),%rdx
  400d0c:	48 8b 85 20 ff ff ff 	mov    -0xe0(%rbp),%rax
  400d13:	48 89 d6             	mov    %rdx,%rsi
  400d16:	48 89 c7             	mov    %rax,%rdi
  400d19:	e8 e0 00 00 00       	callq  400dfe <createAugMatrix>
  400d1e:	48 89 85 28 ff ff ff 	mov    %rax,-0xd8(%rbp)
  400d25:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
  400d2c:	48 89 c7             	mov    %rax,%rdi
  400d2f:	e8 26 0e 00 00       	callq  401b5a <showMatrix>
  400d34:	bf 6b 22 40 00       	mov    $0x40226b,%edi
  400d39:	e8 f2 f8 ff ff       	callq  400630 <puts@plt>
  400d3e:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
  400d45:	48 89 c7             	mov    %rax,%rdi
  400d48:	e8 e0 06 00 00       	callq  40142d <reduceMatrix>
  400d4d:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
  400d54:	48 89 c7             	mov    %rax,%rdi
  400d57:	e8 fe 0d 00 00       	callq  401b5a <showMatrix>
  400d5c:	48 8b 85 e8 fe ff ff 	mov    -0x118(%rbp),%rax
  400d63:	48 89 c7             	mov    %rax,%rdi
  400d66:	e8 19 0f 00 00       	callq  401c84 <freeMatrix>
  400d6b:	48 8b 85 f0 fe ff ff 	mov    -0x110(%rbp),%rax
  400d72:	48 89 c7             	mov    %rax,%rdi
  400d75:	e8 0a 0f 00 00       	callq  401c84 <freeMatrix>
  400d7a:	48 8b 85 f8 fe ff ff 	mov    -0x108(%rbp),%rax
  400d81:	48 89 c7             	mov    %rax,%rdi
  400d84:	e8 fb 0e 00 00       	callq  401c84 <freeMatrix>
  400d89:	48 8b 85 00 ff ff ff 	mov    -0x100(%rbp),%rax
  400d90:	48 89 c7             	mov    %rax,%rdi
  400d93:	e8 ec 0e 00 00       	callq  401c84 <freeMatrix>
  400d98:	48 8b 85 08 ff ff ff 	mov    -0xf8(%rbp),%rax
  400d9f:	48 89 c7             	mov    %rax,%rdi
  400da2:	e8 dd 0e 00 00       	callq  401c84 <freeMatrix>
  400da7:	48 8b 85 10 ff ff ff 	mov    -0xf0(%rbp),%rax
  400dae:	48 89 c7             	mov    %rax,%rdi
  400db1:	e8 ce 0e 00 00       	callq  401c84 <freeMatrix>
  400db6:	48 8b 85 18 ff ff ff 	mov    -0xe8(%rbp),%rax
  400dbd:	48 89 c7             	mov    %rax,%rdi
  400dc0:	e8 bf 0e 00 00       	callq  401c84 <freeMatrix>
  400dc5:	48 8b 85 20 ff ff ff 	mov    -0xe0(%rbp),%rax
  400dcc:	48 89 c7             	mov    %rax,%rdi
  400dcf:	e8 b0 0e 00 00       	callq  401c84 <freeMatrix>
  400dd4:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
  400ddb:	48 89 c7             	mov    %rax,%rdi
  400dde:	e8 a1 0e 00 00       	callq  401c84 <freeMatrix>
  400de3:	b8 00 00 00 00       	mov    $0x0,%eax
  400de8:	48 8b 4d f8          	mov    -0x8(%rbp),%rcx
  400dec:	64 48 33 0c 25 28 00 	xor    %fs:0x28,%rcx
  400df3:	00 00 
  400df5:	74 05                	je     400dfc <main+0x636>
  400df7:	e8 44 f8 ff ff       	callq  400640 <__stack_chk_fail@plt>
  400dfc:	c9                   	leaveq 
  400dfd:	c3                   	retq   

0000000000400dfe <createAugMatrix>:
  400dfe:	55                   	push   %rbp
  400dff:	48 89 e5             	mov    %rsp,%rbp
  400e02:	48 83 ec 30          	sub    $0x30,%rsp
  400e06:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  400e0a:	48 89 75 d0          	mov    %rsi,-0x30(%rbp)
  400e0e:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  400e12:	8b 50 08             	mov    0x8(%rax),%edx
  400e15:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  400e19:	8b 40 08             	mov    0x8(%rax),%eax
  400e1c:	39 c2                	cmp    %eax,%edx
  400e1e:	74 14                	je     400e34 <createAugMatrix+0x36>
  400e20:	ba 01 00 00 00       	mov    $0x1,%edx
  400e25:	be d0 22 40 00       	mov    $0x4022d0,%esi
  400e2a:	bf e2 22 40 00       	mov    $0x4022e2,%edi
  400e2f:	e8 2d 12 00 00       	callq  402061 <printError>
  400e34:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  400e38:	8b 50 0c             	mov    0xc(%rax),%edx
  400e3b:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  400e3f:	8b 40 0c             	mov    0xc(%rax),%eax
  400e42:	01 c2                	add    %eax,%edx
  400e44:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  400e48:	8b 40 08             	mov    0x8(%rax),%eax
  400e4b:	89 d6                	mov    %edx,%esi
  400e4d:	89 c7                	mov    %eax,%edi
  400e4f:	e8 cf 08 00 00       	callq  401723 <createMatrix>
  400e54:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  400e58:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  400e5c:	8b 50 0c             	mov    0xc(%rax),%edx
  400e5f:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  400e63:	89 50 10             	mov    %edx,0x10(%rax)
  400e66:	c7 45 ec 00 00 00 00 	movl   $0x0,-0x14(%rbp)
  400e6d:	e9 de 00 00 00       	jmpq   400f50 <createAugMatrix+0x152>
  400e72:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%rbp)
  400e79:	eb 54                	jmp    400ecf <createAugMatrix+0xd1>
  400e7b:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  400e7f:	48 8b 00             	mov    (%rax),%rax
  400e82:	8b 55 ec             	mov    -0x14(%rbp),%edx
  400e85:	48 63 d2             	movslq %edx,%rdx
  400e88:	48 c1 e2 03          	shl    $0x3,%rdx
  400e8c:	48 01 d0             	add    %rdx,%rax
  400e8f:	48 8b 00             	mov    (%rax),%rax
  400e92:	8b 55 f0             	mov    -0x10(%rbp),%edx
  400e95:	48 63 d2             	movslq %edx,%rdx
  400e98:	48 c1 e2 02          	shl    $0x2,%rdx
  400e9c:	48 01 c2             	add    %rax,%rdx
  400e9f:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  400ea3:	48 8b 00             	mov    (%rax),%rax
  400ea6:	8b 4d ec             	mov    -0x14(%rbp),%ecx
  400ea9:	48 63 c9             	movslq %ecx,%rcx
  400eac:	48 c1 e1 03          	shl    $0x3,%rcx
  400eb0:	48 01 c8             	add    %rcx,%rax
  400eb3:	48 8b 00             	mov    (%rax),%rax
  400eb6:	8b 4d f0             	mov    -0x10(%rbp),%ecx
  400eb9:	48 63 c9             	movslq %ecx,%rcx
  400ebc:	48 c1 e1 02          	shl    $0x2,%rcx
  400ec0:	48 01 c8             	add    %rcx,%rax
  400ec3:	f3 0f 10 00          	movss  (%rax),%xmm0
  400ec7:	f3 0f 11 02          	movss  %xmm0,(%rdx)
  400ecb:	83 45 f0 01          	addl   $0x1,-0x10(%rbp)
  400ecf:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  400ed3:	8b 40 0c             	mov    0xc(%rax),%eax
  400ed6:	3b 45 f0             	cmp    -0x10(%rbp),%eax
  400ed9:	7f a0                	jg     400e7b <createAugMatrix+0x7d>
  400edb:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%rbp)
  400ee2:	eb 5c                	jmp    400f40 <createAugMatrix+0x142>
  400ee4:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  400ee8:	48 8b 00             	mov    (%rax),%rax
  400eeb:	8b 55 ec             	mov    -0x14(%rbp),%edx
  400eee:	48 63 d2             	movslq %edx,%rdx
  400ef1:	48 c1 e2 03          	shl    $0x3,%rdx
  400ef5:	48 01 d0             	add    %rdx,%rax
  400ef8:	48 8b 10             	mov    (%rax),%rdx
  400efb:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  400eff:	8b 48 0c             	mov    0xc(%rax),%ecx
  400f02:	8b 45 f4             	mov    -0xc(%rbp),%eax
  400f05:	01 c8                	add    %ecx,%eax
  400f07:	48 98                	cltq   
  400f09:	48 c1 e0 02          	shl    $0x2,%rax
  400f0d:	48 01 c2             	add    %rax,%rdx
  400f10:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  400f14:	48 8b 00             	mov    (%rax),%rax
  400f17:	8b 4d ec             	mov    -0x14(%rbp),%ecx
  400f1a:	48 63 c9             	movslq %ecx,%rcx
  400f1d:	48 c1 e1 03          	shl    $0x3,%rcx
  400f21:	48 01 c8             	add    %rcx,%rax
  400f24:	48 8b 00             	mov    (%rax),%rax
  400f27:	8b 4d f4             	mov    -0xc(%rbp),%ecx
  400f2a:	48 63 c9             	movslq %ecx,%rcx
  400f2d:	48 c1 e1 02          	shl    $0x2,%rcx
  400f31:	48 01 c8             	add    %rcx,%rax
  400f34:	f3 0f 10 00          	movss  (%rax),%xmm0
  400f38:	f3 0f 11 02          	movss  %xmm0,(%rdx)
  400f3c:	83 45 f4 01          	addl   $0x1,-0xc(%rbp)
  400f40:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  400f44:	8b 40 0c             	mov    0xc(%rax),%eax
  400f47:	3b 45 f4             	cmp    -0xc(%rbp),%eax
  400f4a:	7f 98                	jg     400ee4 <createAugMatrix+0xe6>
  400f4c:	83 45 ec 01          	addl   $0x1,-0x14(%rbp)
  400f50:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  400f54:	8b 40 08             	mov    0x8(%rax),%eax
  400f57:	3b 45 ec             	cmp    -0x14(%rbp),%eax
  400f5a:	0f 8f 12 ff ff ff    	jg     400e72 <createAugMatrix+0x74>
  400f60:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  400f64:	c9                   	leaveq 
  400f65:	c3                   	retq   

0000000000400f66 <absFloat.2856>:
  400f66:	55                   	push   %rbp
  400f67:	48 89 e5             	mov    %rsp,%rbp
  400f6a:	f3 0f 11 45 fc       	movss  %xmm0,-0x4(%rbp)
  400f6f:	4c 89 55 f0          	mov    %r10,-0x10(%rbp)
  400f73:	66 0f ef c0          	pxor   %xmm0,%xmm0
  400f77:	0f 2e 45 fc          	ucomiss -0x4(%rbp),%xmm0
  400f7b:	76 12                	jbe    400f8f <absFloat.2856+0x29>
  400f7d:	f3 0f 10 4d fc       	movss  -0x4(%rbp),%xmm1
  400f82:	f3 0f 10 05 c6 13 00 	movss  0x13c6(%rip),%xmm0        # 402350 <_IO_stdin_used+0x1f0>
  400f89:	00 
  400f8a:	0f 57 c1             	xorps  %xmm1,%xmm0
  400f8d:	eb 05                	jmp    400f94 <absFloat.2856+0x2e>
  400f8f:	f3 0f 10 45 fc       	movss  -0x4(%rbp),%xmm0
  400f94:	5d                   	pop    %rbp
  400f95:	c3                   	retq   

0000000000400f96 <roundToZero>:
  400f96:	55                   	push   %rbp
  400f97:	48 89 e5             	mov    %rsp,%rbp
  400f9a:	48 83 ec 20          	sub    $0x20,%rsp
  400f9e:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  400fa2:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  400fa9:	00 00 
  400fab:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  400faf:	31 c0                	xor    %eax,%eax
  400fb1:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  400fb5:	8b 00                	mov    (%rax),%eax
  400fb7:	48 8d 55 f7          	lea    -0x9(%rbp),%rdx
  400fbb:	49 89 d2             	mov    %rdx,%r10
  400fbe:	89 45 e4             	mov    %eax,-0x1c(%rbp)
  400fc1:	f3 0f 10 45 e4       	movss  -0x1c(%rbp),%xmm0
  400fc6:	e8 9b ff ff ff       	callq  400f66 <absFloat.2856>
  400fcb:	f3 0f 5a c0          	cvtss2sd %xmm0,%xmm0
  400fcf:	f2 0f 10 0d 89 13 00 	movsd  0x1389(%rip),%xmm1        # 402360 <_IO_stdin_used+0x200>
  400fd6:	00 
  400fd7:	66 0f 2e c8          	ucomisd %xmm0,%xmm1
  400fdb:	77 02                	ja     400fdf <roundToZero+0x49>
  400fdd:	eb 0c                	jmp    400feb <roundToZero+0x55>
  400fdf:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  400fe3:	66 0f ef c0          	pxor   %xmm0,%xmm0
  400fe7:	f3 0f 11 00          	movss  %xmm0,(%rax)
  400feb:	90                   	nop
  400fec:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  400ff0:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
  400ff7:	00 00 
  400ff9:	74 05                	je     401000 <roundToZero+0x6a>
  400ffb:	e8 40 f6 ff ff       	callq  400640 <__stack_chk_fail@plt>
  401000:	c9                   	leaveq 
  401001:	c3                   	retq   

0000000000401002 <normaliseMatrix>:
  401002:	55                   	push   %rbp
  401003:	48 89 e5             	mov    %rsp,%rbp
  401006:	48 83 ec 20          	sub    $0x20,%rsp
  40100a:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  40100e:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%rbp)
  401015:	e9 48 01 00 00       	jmpq   401162 <normaliseMatrix+0x160>
  40101a:	66 0f ef c0          	pxor   %xmm0,%xmm0
  40101e:	f3 0f 11 45 f4       	movss  %xmm0,-0xc(%rbp)
  401023:	c7 45 f8 00 00 00 00 	movl   $0x0,-0x8(%rbp)
  40102a:	eb 6d                	jmp    401099 <normaliseMatrix+0x97>
  40102c:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  401030:	48 8b 00             	mov    (%rax),%rax
  401033:	8b 55 f0             	mov    -0x10(%rbp),%edx
  401036:	48 63 d2             	movslq %edx,%rdx
  401039:	48 c1 e2 03          	shl    $0x3,%rdx
  40103d:	48 01 d0             	add    %rdx,%rax
  401040:	48 8b 00             	mov    (%rax),%rax
  401043:	8b 55 f8             	mov    -0x8(%rbp),%edx
  401046:	48 63 d2             	movslq %edx,%rdx
  401049:	48 c1 e2 02          	shl    $0x2,%rdx
  40104d:	48 01 d0             	add    %rdx,%rax
  401050:	f3 0f 10 00          	movss  (%rax),%xmm0
  401054:	66 0f ef c9          	pxor   %xmm1,%xmm1
  401058:	0f 2e c1             	ucomiss %xmm1,%xmm0
  40105b:	7a 09                	jp     401066 <normaliseMatrix+0x64>
  40105d:	66 0f ef c9          	pxor   %xmm1,%xmm1
  401061:	0f 2e c1             	ucomiss %xmm1,%xmm0
  401064:	74 2f                	je     401095 <normaliseMatrix+0x93>
  401066:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  40106a:	48 8b 00             	mov    (%rax),%rax
  40106d:	8b 55 f0             	mov    -0x10(%rbp),%edx
  401070:	48 63 d2             	movslq %edx,%rdx
  401073:	48 c1 e2 03          	shl    $0x3,%rdx
  401077:	48 01 d0             	add    %rdx,%rax
  40107a:	48 8b 00             	mov    (%rax),%rax
  40107d:	8b 55 f8             	mov    -0x8(%rbp),%edx
  401080:	48 63 d2             	movslq %edx,%rdx
  401083:	48 c1 e2 02          	shl    $0x2,%rdx
  401087:	48 01 d0             	add    %rdx,%rax
  40108a:	f3 0f 10 00          	movss  (%rax),%xmm0
  40108e:	f3 0f 11 45 f4       	movss  %xmm0,-0xc(%rbp)
  401093:	eb 10                	jmp    4010a5 <normaliseMatrix+0xa3>
  401095:	83 45 f8 01          	addl   $0x1,-0x8(%rbp)
  401099:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  40109d:	8b 40 0c             	mov    0xc(%rax),%eax
  4010a0:	3b 45 f8             	cmp    -0x8(%rbp),%eax
  4010a3:	7f 87                	jg     40102c <normaliseMatrix+0x2a>
  4010a5:	66 0f ef c0          	pxor   %xmm0,%xmm0
  4010a9:	0f 2e 45 f4          	ucomiss -0xc(%rbp),%xmm0
  4010ad:	7a 0e                	jp     4010bd <normaliseMatrix+0xbb>
  4010af:	66 0f ef c0          	pxor   %xmm0,%xmm0
  4010b3:	0f 2e 45 f4          	ucomiss -0xc(%rbp),%xmm0
  4010b7:	0f 84 a1 00 00 00    	je     40115e <normaliseMatrix+0x15c>
  4010bd:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  4010c4:	e9 85 00 00 00       	jmpq   40114e <normaliseMatrix+0x14c>
  4010c9:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  4010cd:	48 8b 00             	mov    (%rax),%rax
  4010d0:	8b 55 f0             	mov    -0x10(%rbp),%edx
  4010d3:	48 63 d2             	movslq %edx,%rdx
  4010d6:	48 c1 e2 03          	shl    $0x3,%rdx
  4010da:	48 01 d0             	add    %rdx,%rax
  4010dd:	48 8b 00             	mov    (%rax),%rax
  4010e0:	8b 55 fc             	mov    -0x4(%rbp),%edx
  4010e3:	48 63 d2             	movslq %edx,%rdx
  4010e6:	48 c1 e2 02          	shl    $0x2,%rdx
  4010ea:	48 01 c2             	add    %rax,%rdx
  4010ed:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  4010f1:	48 8b 00             	mov    (%rax),%rax
  4010f4:	8b 4d f0             	mov    -0x10(%rbp),%ecx
  4010f7:	48 63 c9             	movslq %ecx,%rcx
  4010fa:	48 c1 e1 03          	shl    $0x3,%rcx
  4010fe:	48 01 c8             	add    %rcx,%rax
  401101:	48 8b 00             	mov    (%rax),%rax
  401104:	8b 4d fc             	mov    -0x4(%rbp),%ecx
  401107:	48 63 c9             	movslq %ecx,%rcx
  40110a:	48 c1 e1 02          	shl    $0x2,%rcx
  40110e:	48 01 c8             	add    %rcx,%rax
  401111:	f3 0f 10 00          	movss  (%rax),%xmm0
  401115:	f3 0f 5e 45 f4       	divss  -0xc(%rbp),%xmm0
  40111a:	f3 0f 11 02          	movss  %xmm0,(%rdx)
  40111e:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  401122:	48 8b 00             	mov    (%rax),%rax
  401125:	8b 55 f0             	mov    -0x10(%rbp),%edx
  401128:	48 63 d2             	movslq %edx,%rdx
  40112b:	48 c1 e2 03          	shl    $0x3,%rdx
  40112f:	48 01 d0             	add    %rdx,%rax
  401132:	48 8b 00             	mov    (%rax),%rax
  401135:	8b 55 fc             	mov    -0x4(%rbp),%edx
  401138:	48 63 d2             	movslq %edx,%rdx
  40113b:	48 c1 e2 02          	shl    $0x2,%rdx
  40113f:	48 01 d0             	add    %rdx,%rax
  401142:	48 89 c7             	mov    %rax,%rdi
  401145:	e8 4c fe ff ff       	callq  400f96 <roundToZero>
  40114a:	83 45 fc 01          	addl   $0x1,-0x4(%rbp)
  40114e:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  401152:	8b 40 0c             	mov    0xc(%rax),%eax
  401155:	3b 45 fc             	cmp    -0x4(%rbp),%eax
  401158:	0f 8f 6b ff ff ff    	jg     4010c9 <normaliseMatrix+0xc7>
  40115e:	83 45 f0 01          	addl   $0x1,-0x10(%rbp)
  401162:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  401166:	8b 40 08             	mov    0x8(%rax),%eax
  401169:	3b 45 f0             	cmp    -0x10(%rbp),%eax
  40116c:	0f 8f a8 fe ff ff    	jg     40101a <normaliseMatrix+0x18>
  401172:	90                   	nop
  401173:	c9                   	leaveq 
  401174:	c3                   	retq   

0000000000401175 <swapRows>:
  401175:	55                   	push   %rbp
  401176:	48 89 e5             	mov    %rsp,%rbp
  401179:	48 83 ec 20          	sub    $0x20,%rsp
  40117d:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  401181:	89 75 e4             	mov    %esi,-0x1c(%rbp)
  401184:	89 55 e0             	mov    %edx,-0x20(%rbp)
  401187:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  40118b:	8b 40 08             	mov    0x8(%rax),%eax
  40118e:	3b 45 e4             	cmp    -0x1c(%rbp),%eax
  401191:	7e 0c                	jle    40119f <swapRows+0x2a>
  401193:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  401197:	8b 40 08             	mov    0x8(%rax),%eax
  40119a:	3b 45 e0             	cmp    -0x20(%rbp),%eax
  40119d:	7f 19                	jg     4011b8 <swapRows+0x43>
  40119f:	ba 01 00 00 00       	mov    $0x1,%edx
  4011a4:	be fc 22 40 00       	mov    $0x4022fc,%esi
  4011a9:	bf 0a 23 40 00       	mov    $0x40230a,%edi
  4011ae:	e8 ae 0e 00 00       	callq  402061 <printError>
  4011b3:	e9 ca 00 00 00       	jmpq   401282 <swapRows+0x10d>
  4011b8:	c7 45 f8 00 00 00 00 	movl   $0x0,-0x8(%rbp)
  4011bf:	e9 ae 00 00 00       	jmpq   401272 <swapRows+0xfd>
  4011c4:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  4011c8:	48 8b 00             	mov    (%rax),%rax
  4011cb:	8b 55 e4             	mov    -0x1c(%rbp),%edx
  4011ce:	48 63 d2             	movslq %edx,%rdx
  4011d1:	48 c1 e2 03          	shl    $0x3,%rdx
  4011d5:	48 01 d0             	add    %rdx,%rax
  4011d8:	48 8b 00             	mov    (%rax),%rax
  4011db:	8b 55 f8             	mov    -0x8(%rbp),%edx
  4011de:	48 63 d2             	movslq %edx,%rdx
  4011e1:	48 c1 e2 02          	shl    $0x2,%rdx
  4011e5:	48 01 d0             	add    %rdx,%rax
  4011e8:	f3 0f 10 00          	movss  (%rax),%xmm0
  4011ec:	f3 0f 11 45 fc       	movss  %xmm0,-0x4(%rbp)
  4011f1:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  4011f5:	48 8b 00             	mov    (%rax),%rax
  4011f8:	8b 55 e4             	mov    -0x1c(%rbp),%edx
  4011fb:	48 63 d2             	movslq %edx,%rdx
  4011fe:	48 c1 e2 03          	shl    $0x3,%rdx
  401202:	48 01 d0             	add    %rdx,%rax
  401205:	48 8b 00             	mov    (%rax),%rax
  401208:	8b 55 f8             	mov    -0x8(%rbp),%edx
  40120b:	48 63 d2             	movslq %edx,%rdx
  40120e:	48 c1 e2 02          	shl    $0x2,%rdx
  401212:	48 01 c2             	add    %rax,%rdx
  401215:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  401219:	48 8b 00             	mov    (%rax),%rax
  40121c:	8b 4d e0             	mov    -0x20(%rbp),%ecx
  40121f:	48 63 c9             	movslq %ecx,%rcx
  401222:	48 c1 e1 03          	shl    $0x3,%rcx
  401226:	48 01 c8             	add    %rcx,%rax
  401229:	48 8b 00             	mov    (%rax),%rax
  40122c:	8b 4d f8             	mov    -0x8(%rbp),%ecx
  40122f:	48 63 c9             	movslq %ecx,%rcx
  401232:	48 c1 e1 02          	shl    $0x2,%rcx
  401236:	48 01 c8             	add    %rcx,%rax
  401239:	f3 0f 10 00          	movss  (%rax),%xmm0
  40123d:	f3 0f 11 02          	movss  %xmm0,(%rdx)
  401241:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  401245:	48 8b 00             	mov    (%rax),%rax
  401248:	8b 55 e0             	mov    -0x20(%rbp),%edx
  40124b:	48 63 d2             	movslq %edx,%rdx
  40124e:	48 c1 e2 03          	shl    $0x3,%rdx
  401252:	48 01 d0             	add    %rdx,%rax
  401255:	48 8b 00             	mov    (%rax),%rax
  401258:	8b 55 f8             	mov    -0x8(%rbp),%edx
  40125b:	48 63 d2             	movslq %edx,%rdx
  40125e:	48 c1 e2 02          	shl    $0x2,%rdx
  401262:	48 01 d0             	add    %rdx,%rax
  401265:	f3 0f 10 45 fc       	movss  -0x4(%rbp),%xmm0
  40126a:	f3 0f 11 00          	movss  %xmm0,(%rax)
  40126e:	83 45 f8 01          	addl   $0x1,-0x8(%rbp)
  401272:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  401276:	8b 40 0c             	mov    0xc(%rax),%eax
  401279:	3b 45 f8             	cmp    -0x8(%rbp),%eax
  40127c:	0f 8f 42 ff ff ff    	jg     4011c4 <swapRows+0x4f>
  401282:	c9                   	leaveq 
  401283:	c3                   	retq   

0000000000401284 <subtractRow>:
  401284:	55                   	push   %rbp
  401285:	48 89 e5             	mov    %rsp,%rbp
  401288:	48 83 ec 20          	sub    $0x20,%rsp
  40128c:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  401290:	89 75 e4             	mov    %esi,-0x1c(%rbp)
  401293:	89 55 e0             	mov    %edx,-0x20(%rbp)
  401296:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  40129a:	8b 40 08             	mov    0x8(%rax),%eax
  40129d:	3b 45 e4             	cmp    -0x1c(%rbp),%eax
  4012a0:	7e 0c                	jle    4012ae <subtractRow+0x2a>
  4012a2:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  4012a6:	8b 40 08             	mov    0x8(%rax),%eax
  4012a9:	3b 45 e0             	cmp    -0x20(%rbp),%eax
  4012ac:	7f 19                	jg     4012c7 <subtractRow+0x43>
  4012ae:	ba 01 00 00 00       	mov    $0x1,%edx
  4012b3:	be fc 22 40 00       	mov    $0x4022fc,%esi
  4012b8:	bf 1d 23 40 00       	mov    $0x40231d,%edi
  4012bd:	e8 9f 0d 00 00       	callq  402061 <printError>
  4012c2:	e9 c8 00 00 00       	jmpq   40138f <subtractRow+0x10b>
  4012c7:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  4012ce:	e9 ac 00 00 00       	jmpq   40137f <subtractRow+0xfb>
  4012d3:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  4012d7:	48 8b 00             	mov    (%rax),%rax
  4012da:	8b 55 e4             	mov    -0x1c(%rbp),%edx
  4012dd:	48 63 d2             	movslq %edx,%rdx
  4012e0:	48 c1 e2 03          	shl    $0x3,%rdx
  4012e4:	48 01 d0             	add    %rdx,%rax
  4012e7:	48 8b 00             	mov    (%rax),%rax
  4012ea:	8b 55 fc             	mov    -0x4(%rbp),%edx
  4012ed:	48 63 d2             	movslq %edx,%rdx
  4012f0:	48 c1 e2 02          	shl    $0x2,%rdx
  4012f4:	48 01 c2             	add    %rax,%rdx
  4012f7:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  4012fb:	48 8b 00             	mov    (%rax),%rax
  4012fe:	8b 4d e4             	mov    -0x1c(%rbp),%ecx
  401301:	48 63 c9             	movslq %ecx,%rcx
  401304:	48 c1 e1 03          	shl    $0x3,%rcx
  401308:	48 01 c8             	add    %rcx,%rax
  40130b:	48 8b 00             	mov    (%rax),%rax
  40130e:	8b 4d fc             	mov    -0x4(%rbp),%ecx
  401311:	48 63 c9             	movslq %ecx,%rcx
  401314:	48 c1 e1 02          	shl    $0x2,%rcx
  401318:	48 01 c8             	add    %rcx,%rax
  40131b:	f3 0f 10 00          	movss  (%rax),%xmm0
  40131f:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  401323:	48 8b 00             	mov    (%rax),%rax
  401326:	8b 4d e0             	mov    -0x20(%rbp),%ecx
  401329:	48 63 c9             	movslq %ecx,%rcx
  40132c:	48 c1 e1 03          	shl    $0x3,%rcx
  401330:	48 01 c8             	add    %rcx,%rax
  401333:	48 8b 00             	mov    (%rax),%rax
  401336:	8b 4d fc             	mov    -0x4(%rbp),%ecx
  401339:	48 63 c9             	movslq %ecx,%rcx
  40133c:	48 c1 e1 02          	shl    $0x2,%rcx
  401340:	48 01 c8             	add    %rcx,%rax
  401343:	f3 0f 10 08          	movss  (%rax),%xmm1
  401347:	f3 0f 5c c1          	subss  %xmm1,%xmm0
  40134b:	f3 0f 11 02          	movss  %xmm0,(%rdx)
  40134f:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  401353:	48 8b 00             	mov    (%rax),%rax
  401356:	8b 55 e4             	mov    -0x1c(%rbp),%edx
  401359:	48 63 d2             	movslq %edx,%rdx
  40135c:	48 c1 e2 03          	shl    $0x3,%rdx
  401360:	48 01 d0             	add    %rdx,%rax
  401363:	48 8b 00             	mov    (%rax),%rax
  401366:	8b 55 fc             	mov    -0x4(%rbp),%edx
  401369:	48 63 d2             	movslq %edx,%rdx
  40136c:	48 c1 e2 02          	shl    $0x2,%rdx
  401370:	48 01 d0             	add    %rdx,%rax
  401373:	48 89 c7             	mov    %rax,%rdi
  401376:	e8 1b fc ff ff       	callq  400f96 <roundToZero>
  40137b:	83 45 fc 01          	addl   $0x1,-0x4(%rbp)
  40137f:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  401383:	8b 40 0c             	mov    0xc(%rax),%eax
  401386:	3b 45 fc             	cmp    -0x4(%rbp),%eax
  401389:	0f 8f 44 ff ff ff    	jg     4012d3 <subtractRow+0x4f>
  40138f:	c9                   	leaveq 
  401390:	c3                   	retq   

0000000000401391 <checkLeadColumn>:
  401391:	55                   	push   %rbp
  401392:	48 89 e5             	mov    %rsp,%rbp
  401395:	48 83 ec 20          	sub    $0x20,%rsp
  401399:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  40139d:	89 75 e4             	mov    %esi,-0x1c(%rbp)
  4013a0:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  4013a4:	8b 40 08             	mov    0x8(%rax),%eax
  4013a7:	3b 45 e4             	cmp    -0x1c(%rbp),%eax
  4013aa:	7f 1b                	jg     4013c7 <checkLeadColumn+0x36>
  4013ac:	ba 01 00 00 00       	mov    $0x1,%edx
  4013b1:	be fc 22 40 00       	mov    $0x4022fc,%esi
  4013b6:	bf 30 23 40 00       	mov    $0x402330,%edi
  4013bb:	e8 a1 0c 00 00       	callq  402061 <printError>
  4013c0:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  4013c5:	eb 64                	jmp    40142b <checkLeadColumn+0x9a>
  4013c7:	c7 45 f8 00 00 00 00 	movl   $0x0,-0x8(%rbp)
  4013ce:	eb 4a                	jmp    40141a <checkLeadColumn+0x89>
  4013d0:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  4013d4:	48 8b 00             	mov    (%rax),%rax
  4013d7:	8b 55 e4             	mov    -0x1c(%rbp),%edx
  4013da:	48 63 d2             	movslq %edx,%rdx
  4013dd:	48 c1 e2 03          	shl    $0x3,%rdx
  4013e1:	48 01 d0             	add    %rdx,%rax
  4013e4:	48 8b 00             	mov    (%rax),%rax
  4013e7:	8b 55 f8             	mov    -0x8(%rbp),%edx
  4013ea:	48 63 d2             	movslq %edx,%rdx
  4013ed:	48 c1 e2 02          	shl    $0x2,%rdx
  4013f1:	48 01 d0             	add    %rdx,%rax
  4013f4:	f3 0f 10 00          	movss  (%rax),%xmm0
  4013f8:	f3 0f 11 45 fc       	movss  %xmm0,-0x4(%rbp)
  4013fd:	66 0f ef c0          	pxor   %xmm0,%xmm0
  401401:	0f 2e 45 fc          	ucomiss -0x4(%rbp),%xmm0
  401405:	7a 0a                	jp     401411 <checkLeadColumn+0x80>
  401407:	66 0f ef c0          	pxor   %xmm0,%xmm0
  40140b:	0f 2e 45 fc          	ucomiss -0x4(%rbp),%xmm0
  40140f:	74 05                	je     401416 <checkLeadColumn+0x85>
  401411:	8b 45 f8             	mov    -0x8(%rbp),%eax
  401414:	eb 15                	jmp    40142b <checkLeadColumn+0x9a>
  401416:	83 45 f8 01          	addl   $0x1,-0x8(%rbp)
  40141a:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  40141e:	8b 40 0c             	mov    0xc(%rax),%eax
  401421:	3b 45 f8             	cmp    -0x8(%rbp),%eax
  401424:	7f aa                	jg     4013d0 <checkLeadColumn+0x3f>
  401426:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  40142b:	c9                   	leaveq 
  40142c:	c3                   	retq   

000000000040142d <reduceMatrix>:
  40142d:	55                   	push   %rbp
  40142e:	48 89 e5             	mov    %rsp,%rbp
  401431:	48 83 ec 50          	sub    $0x50,%rsp
  401435:	48 89 7d b8          	mov    %rdi,-0x48(%rbp)
  401439:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  40143d:	48 89 c7             	mov    %rax,%rdi
  401440:	e8 bd fb ff ff       	callq  401002 <normaliseMatrix>
  401445:	c7 45 c8 00 00 00 00 	movl   $0x0,-0x38(%rbp)
  40144c:	e9 d2 00 00 00       	jmpq   401523 <reduceMatrix+0xf6>
  401451:	c7 45 cc 00 00 00 00 	movl   $0x0,-0x34(%rbp)
  401458:	c7 45 d0 00 00 00 00 	movl   $0x0,-0x30(%rbp)
  40145f:	c7 45 d4 00 00 00 00 	movl   $0x0,-0x2c(%rbp)
  401466:	e9 98 00 00 00       	jmpq   401503 <reduceMatrix+0xd6>
  40146b:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  40146f:	48 8b 00             	mov    (%rax),%rax
  401472:	8b 55 d4             	mov    -0x2c(%rbp),%edx
  401475:	48 63 d2             	movslq %edx,%rdx
  401478:	48 c1 e2 03          	shl    $0x3,%rdx
  40147c:	48 01 d0             	add    %rdx,%rax
  40147f:	48 8b 00             	mov    (%rax),%rax
  401482:	8b 55 c8             	mov    -0x38(%rbp),%edx
  401485:	48 63 d2             	movslq %edx,%rdx
  401488:	48 c1 e2 02          	shl    $0x2,%rdx
  40148c:	48 01 d0             	add    %rdx,%rax
  40148f:	f3 0f 10 00          	movss  (%rax),%xmm0
  401493:	f3 0f 11 45 f0       	movss  %xmm0,-0x10(%rbp)
  401498:	8b 55 d4             	mov    -0x2c(%rbp),%edx
  40149b:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  40149f:	89 d6                	mov    %edx,%esi
  4014a1:	48 89 c7             	mov    %rax,%rdi
  4014a4:	e8 e8 fe ff ff       	callq  401391 <checkLeadColumn>
  4014a9:	89 45 f4             	mov    %eax,-0xc(%rbp)
  4014ac:	66 0f ef c0          	pxor   %xmm0,%xmm0
  4014b0:	0f 2e 45 f0          	ucomiss -0x10(%rbp),%xmm0
  4014b4:	7a 0a                	jp     4014c0 <reduceMatrix+0x93>
  4014b6:	66 0f ef c0          	pxor   %xmm0,%xmm0
  4014ba:	0f 2e 45 f0          	ucomiss -0x10(%rbp),%xmm0
  4014be:	74 3f                	je     4014ff <reduceMatrix+0xd2>
  4014c0:	8b 45 c8             	mov    -0x38(%rbp),%eax
  4014c3:	3b 45 f4             	cmp    -0xc(%rbp),%eax
  4014c6:	75 37                	jne    4014ff <reduceMatrix+0xd2>
  4014c8:	83 7d d0 00          	cmpl   $0x0,-0x30(%rbp)
  4014cc:	75 0f                	jne    4014dd <reduceMatrix+0xb0>
  4014ce:	8b 45 d4             	mov    -0x2c(%rbp),%eax
  4014d1:	89 45 cc             	mov    %eax,-0x34(%rbp)
  4014d4:	c7 45 d0 01 00 00 00 	movl   $0x1,-0x30(%rbp)
  4014db:	eb 22                	jmp    4014ff <reduceMatrix+0xd2>
  4014dd:	c7 45 d0 00 00 00 00 	movl   $0x0,-0x30(%rbp)
  4014e4:	8b 55 cc             	mov    -0x34(%rbp),%edx
  4014e7:	8b 4d d4             	mov    -0x2c(%rbp),%ecx
  4014ea:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  4014ee:	89 ce                	mov    %ecx,%esi
  4014f0:	48 89 c7             	mov    %rax,%rdi
  4014f3:	e8 8c fd ff ff       	callq  401284 <subtractRow>
  4014f8:	c7 45 d4 ff ff ff ff 	movl   $0xffffffff,-0x2c(%rbp)
  4014ff:	83 45 d4 01          	addl   $0x1,-0x2c(%rbp)
  401503:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  401507:	8b 40 08             	mov    0x8(%rax),%eax
  40150a:	3b 45 d4             	cmp    -0x2c(%rbp),%eax
  40150d:	0f 8f 58 ff ff ff    	jg     40146b <reduceMatrix+0x3e>
  401513:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  401517:	48 89 c7             	mov    %rax,%rdi
  40151a:	e8 e3 fa ff ff       	callq  401002 <normaliseMatrix>
  40151f:	83 45 c8 01          	addl   $0x1,-0x38(%rbp)
  401523:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  401527:	8b 40 10             	mov    0x10(%rax),%eax
  40152a:	3b 45 c8             	cmp    -0x38(%rbp),%eax
  40152d:	0f 8f 1e ff ff ff    	jg     401451 <reduceMatrix+0x24>
  401533:	c7 45 d8 00 00 00 00 	movl   $0x0,-0x28(%rbp)
  40153a:	e9 d1 01 00 00       	jmpq   401710 <reduceMatrix+0x2e3>
  40153f:	c7 45 dc 00 00 00 00 	movl   $0x0,-0x24(%rbp)
  401546:	c7 45 e0 00 00 00 00 	movl   $0x0,-0x20(%rbp)
  40154d:	66 0f ef c0          	pxor   %xmm0,%xmm0
  401551:	f3 0f 11 45 e4       	movss  %xmm0,-0x1c(%rbp)
  401556:	c7 45 e8 00 00 00 00 	movl   $0x0,-0x18(%rbp)
  40155d:	e9 9a 01 00 00       	jmpq   4016fc <reduceMatrix+0x2cf>
  401562:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  401566:	48 8b 00             	mov    (%rax),%rax
  401569:	8b 55 e8             	mov    -0x18(%rbp),%edx
  40156c:	48 63 d2             	movslq %edx,%rdx
  40156f:	48 c1 e2 03          	shl    $0x3,%rdx
  401573:	48 01 d0             	add    %rdx,%rax
  401576:	48 8b 00             	mov    (%rax),%rax
  401579:	8b 55 d8             	mov    -0x28(%rbp),%edx
  40157c:	48 63 d2             	movslq %edx,%rdx
  40157f:	48 c1 e2 02          	shl    $0x2,%rdx
  401583:	48 01 d0             	add    %rdx,%rax
  401586:	f3 0f 10 00          	movss  (%rax),%xmm0
  40158a:	f3 0f 11 45 f8       	movss  %xmm0,-0x8(%rbp)
  40158f:	8b 55 e8             	mov    -0x18(%rbp),%edx
  401592:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  401596:	89 d6                	mov    %edx,%esi
  401598:	48 89 c7             	mov    %rax,%rdi
  40159b:	e8 f1 fd ff ff       	callq  401391 <checkLeadColumn>
  4015a0:	89 45 fc             	mov    %eax,-0x4(%rbp)
  4015a3:	66 0f ef c0          	pxor   %xmm0,%xmm0
  4015a7:	0f 2e 45 f8          	ucomiss -0x8(%rbp),%xmm0
  4015ab:	7a 0a                	jp     4015b7 <reduceMatrix+0x18a>
  4015ad:	66 0f ef c0          	pxor   %xmm0,%xmm0
  4015b1:	0f 2e 45 f8          	ucomiss -0x8(%rbp),%xmm0
  4015b5:	74 2a                	je     4015e1 <reduceMatrix+0x1b4>
  4015b7:	8b 45 d8             	mov    -0x28(%rbp),%eax
  4015ba:	3b 45 fc             	cmp    -0x4(%rbp),%eax
  4015bd:	74 22                	je     4015e1 <reduceMatrix+0x1b4>
  4015bf:	83 7d e0 00          	cmpl   $0x0,-0x20(%rbp)
  4015c3:	75 1c                	jne    4015e1 <reduceMatrix+0x1b4>
  4015c5:	f3 0f 10 45 f8       	movss  -0x8(%rbp),%xmm0
  4015ca:	f3 0f 11 45 e4       	movss  %xmm0,-0x1c(%rbp)
  4015cf:	8b 45 e8             	mov    -0x18(%rbp),%eax
  4015d2:	89 45 dc             	mov    %eax,-0x24(%rbp)
  4015d5:	c7 45 e0 01 00 00 00 	movl   $0x1,-0x20(%rbp)
  4015dc:	e9 17 01 00 00       	jmpq   4016f8 <reduceMatrix+0x2cb>
  4015e1:	f3 0f 10 05 7f 0d 00 	movss  0xd7f(%rip),%xmm0        # 402368 <_IO_stdin_used+0x208>
  4015e8:	00 
  4015e9:	0f 2e 45 f8          	ucomiss -0x8(%rbp),%xmm0
  4015ed:	0f 8a 05 01 00 00    	jp     4016f8 <reduceMatrix+0x2cb>
  4015f3:	f3 0f 10 05 6d 0d 00 	movss  0xd6d(%rip),%xmm0        # 402368 <_IO_stdin_used+0x208>
  4015fa:	00 
  4015fb:	0f 2e 45 f8          	ucomiss -0x8(%rbp),%xmm0
  4015ff:	0f 85 f3 00 00 00    	jne    4016f8 <reduceMatrix+0x2cb>
  401605:	8b 45 d8             	mov    -0x28(%rbp),%eax
  401608:	3b 45 fc             	cmp    -0x4(%rbp),%eax
  40160b:	0f 85 e7 00 00 00    	jne    4016f8 <reduceMatrix+0x2cb>
  401611:	83 7d e0 00          	cmpl   $0x0,-0x20(%rbp)
  401615:	0f 84 dd 00 00 00    	je     4016f8 <reduceMatrix+0x2cb>
  40161b:	c7 45 ec 00 00 00 00 	movl   $0x0,-0x14(%rbp)
  401622:	e9 b4 00 00 00       	jmpq   4016db <reduceMatrix+0x2ae>
  401627:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  40162b:	48 8b 00             	mov    (%rax),%rax
  40162e:	8b 55 dc             	mov    -0x24(%rbp),%edx
  401631:	48 63 d2             	movslq %edx,%rdx
  401634:	48 c1 e2 03          	shl    $0x3,%rdx
  401638:	48 01 d0             	add    %rdx,%rax
  40163b:	48 8b 00             	mov    (%rax),%rax
  40163e:	8b 55 ec             	mov    -0x14(%rbp),%edx
  401641:	48 63 d2             	movslq %edx,%rdx
  401644:	48 c1 e2 02          	shl    $0x2,%rdx
  401648:	48 01 c2             	add    %rax,%rdx
  40164b:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  40164f:	48 8b 00             	mov    (%rax),%rax
  401652:	8b 4d dc             	mov    -0x24(%rbp),%ecx
  401655:	48 63 c9             	movslq %ecx,%rcx
  401658:	48 c1 e1 03          	shl    $0x3,%rcx
  40165c:	48 01 c8             	add    %rcx,%rax
  40165f:	48 8b 00             	mov    (%rax),%rax
  401662:	8b 4d ec             	mov    -0x14(%rbp),%ecx
  401665:	48 63 c9             	movslq %ecx,%rcx
  401668:	48 c1 e1 02          	shl    $0x2,%rcx
  40166c:	48 01 c8             	add    %rcx,%rax
  40166f:	f3 0f 10 08          	movss  (%rax),%xmm1
  401673:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  401677:	48 8b 00             	mov    (%rax),%rax
  40167a:	8b 4d e8             	mov    -0x18(%rbp),%ecx
  40167d:	48 63 c9             	movslq %ecx,%rcx
  401680:	48 c1 e1 03          	shl    $0x3,%rcx
  401684:	48 01 c8             	add    %rcx,%rax
  401687:	48 8b 00             	mov    (%rax),%rax
  40168a:	8b 4d ec             	mov    -0x14(%rbp),%ecx
  40168d:	48 63 c9             	movslq %ecx,%rcx
  401690:	48 c1 e1 02          	shl    $0x2,%rcx
  401694:	48 01 c8             	add    %rcx,%rax
  401697:	f3 0f 10 00          	movss  (%rax),%xmm0
  40169b:	f3 0f 59 45 e4       	mulss  -0x1c(%rbp),%xmm0
  4016a0:	f3 0f 5c c8          	subss  %xmm0,%xmm1
  4016a4:	0f 28 c1             	movaps %xmm1,%xmm0
  4016a7:	f3 0f 11 02          	movss  %xmm0,(%rdx)
  4016ab:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  4016af:	48 8b 00             	mov    (%rax),%rax
  4016b2:	8b 55 dc             	mov    -0x24(%rbp),%edx
  4016b5:	48 63 d2             	movslq %edx,%rdx
  4016b8:	48 c1 e2 03          	shl    $0x3,%rdx
  4016bc:	48 01 d0             	add    %rdx,%rax
  4016bf:	48 8b 00             	mov    (%rax),%rax
  4016c2:	8b 55 ec             	mov    -0x14(%rbp),%edx
  4016c5:	48 63 d2             	movslq %edx,%rdx
  4016c8:	48 c1 e2 02          	shl    $0x2,%rdx
  4016cc:	48 01 d0             	add    %rdx,%rax
  4016cf:	48 89 c7             	mov    %rax,%rdi
  4016d2:	e8 bf f8 ff ff       	callq  400f96 <roundToZero>
  4016d7:	83 45 ec 01          	addl   $0x1,-0x14(%rbp)
  4016db:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  4016df:	8b 40 0c             	mov    0xc(%rax),%eax
  4016e2:	3b 45 ec             	cmp    -0x14(%rbp),%eax
  4016e5:	0f 8f 3c ff ff ff    	jg     401627 <reduceMatrix+0x1fa>
  4016eb:	8b 45 dc             	mov    -0x24(%rbp),%eax
  4016ee:	89 45 e8             	mov    %eax,-0x18(%rbp)
  4016f1:	c7 45 e0 00 00 00 00 	movl   $0x0,-0x20(%rbp)
  4016f8:	83 45 e8 01          	addl   $0x1,-0x18(%rbp)
  4016fc:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  401700:	8b 40 08             	mov    0x8(%rax),%eax
  401703:	3b 45 e8             	cmp    -0x18(%rbp),%eax
  401706:	0f 8f 56 fe ff ff    	jg     401562 <reduceMatrix+0x135>
  40170c:	83 45 d8 01          	addl   $0x1,-0x28(%rbp)
  401710:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  401714:	8b 40 10             	mov    0x10(%rax),%eax
  401717:	3b 45 d8             	cmp    -0x28(%rbp),%eax
  40171a:	0f 8f 1f fe ff ff    	jg     40153f <reduceMatrix+0x112>
  401720:	90                   	nop
  401721:	c9                   	leaveq 
  401722:	c3                   	retq   

0000000000401723 <createMatrix>:
  401723:	55                   	push   %rbp
  401724:	48 89 e5             	mov    %rsp,%rbp
  401727:	53                   	push   %rbx
  401728:	48 83 ec 28          	sub    $0x28,%rsp
  40172c:	89 7d dc             	mov    %edi,-0x24(%rbp)
  40172f:	89 75 d8             	mov    %esi,-0x28(%rbp)
  401732:	bf 18 00 00 00       	mov    $0x18,%edi
  401737:	e8 54 ef ff ff       	callq  400690 <malloc@plt>
  40173c:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  401740:	8b 45 dc             	mov    -0x24(%rbp),%eax
  401743:	48 98                	cltq   
  401745:	be 08 00 00 00       	mov    $0x8,%esi
  40174a:	48 89 c7             	mov    %rax,%rdi
  40174d:	e8 1e ef ff ff       	callq  400670 <calloc@plt>
  401752:	48 89 c2             	mov    %rax,%rdx
  401755:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  401759:	48 89 10             	mov    %rdx,(%rax)
  40175c:	c7 45 e4 00 00 00 00 	movl   $0x0,-0x1c(%rbp)
  401763:	eb 2e                	jmp    401793 <createMatrix+0x70>
  401765:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  401769:	48 8b 00             	mov    (%rax),%rax
  40176c:	8b 55 e4             	mov    -0x1c(%rbp),%edx
  40176f:	48 63 d2             	movslq %edx,%rdx
  401772:	48 c1 e2 03          	shl    $0x3,%rdx
  401776:	48 8d 1c 10          	lea    (%rax,%rdx,1),%rbx
  40177a:	8b 45 d8             	mov    -0x28(%rbp),%eax
  40177d:	48 98                	cltq   
  40177f:	be 04 00 00 00       	mov    $0x4,%esi
  401784:	48 89 c7             	mov    %rax,%rdi
  401787:	e8 e4 ee ff ff       	callq  400670 <calloc@plt>
  40178c:	48 89 03             	mov    %rax,(%rbx)
  40178f:	83 45 e4 01          	addl   $0x1,-0x1c(%rbp)
  401793:	8b 45 e4             	mov    -0x1c(%rbp),%eax
  401796:	3b 45 dc             	cmp    -0x24(%rbp),%eax
  401799:	7c ca                	jl     401765 <createMatrix+0x42>
  40179b:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  40179f:	8b 55 dc             	mov    -0x24(%rbp),%edx
  4017a2:	89 50 08             	mov    %edx,0x8(%rax)
  4017a5:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  4017a9:	8b 55 d8             	mov    -0x28(%rbp),%edx
  4017ac:	89 50 10             	mov    %edx,0x10(%rax)
  4017af:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  4017b3:	8b 50 10             	mov    0x10(%rax),%edx
  4017b6:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  4017ba:	89 50 0c             	mov    %edx,0xc(%rax)
  4017bd:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  4017c1:	48 83 c4 28          	add    $0x28,%rsp
  4017c5:	5b                   	pop    %rbx
  4017c6:	5d                   	pop    %rbp
  4017c7:	c3                   	retq   

00000000004017c8 <copyMatrix>:
  4017c8:	55                   	push   %rbp
  4017c9:	48 89 e5             	mov    %rsp,%rbp
  4017cc:	48 83 ec 30          	sub    $0x30,%rsp
  4017d0:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  4017d4:	89 75 e4             	mov    %esi,-0x1c(%rbp)
  4017d7:	89 55 e0             	mov    %edx,-0x20(%rbp)
  4017da:	48 89 4d d8          	mov    %rcx,-0x28(%rbp)
  4017de:	8b 45 e0             	mov    -0x20(%rbp),%eax
  4017e1:	48 63 d0             	movslq %eax,%rdx
  4017e4:	48 83 ea 01          	sub    $0x1,%rdx
  4017e8:	48 89 55 f8          	mov    %rdx,-0x8(%rbp)
  4017ec:	48 63 d0             	movslq %eax,%rdx
  4017ef:	49 89 d0             	mov    %rdx,%r8
  4017f2:	41 b9 00 00 00 00    	mov    $0x0,%r9d
  4017f8:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  4017fc:	8b 52 08             	mov    0x8(%rdx),%edx
  4017ff:	3b 55 e4             	cmp    -0x1c(%rbp),%edx
  401802:	75 0c                	jne    401810 <copyMatrix+0x48>
  401804:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  401808:	8b 52 0c             	mov    0xc(%rdx),%edx
  40180b:	3b 55 e0             	cmp    -0x20(%rbp),%edx
  40180e:	74 19                	je     401829 <copyMatrix+0x61>
  401810:	ba 00 00 00 00       	mov    $0x0,%edx
  401815:	be 70 23 40 00       	mov    $0x402370,%esi
  40181a:	bf 8b 23 40 00       	mov    $0x40238b,%edi
  40181f:	e8 3d 08 00 00       	callq  402061 <printError>
  401824:	e9 81 00 00 00       	jmpq   4018aa <copyMatrix+0xe2>
  401829:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%rbp)
  401830:	eb 6c                	jmp    40189e <copyMatrix+0xd6>
  401832:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%rbp)
  401839:	eb 53                	jmp    40188e <copyMatrix+0xc6>
  40183b:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  40183f:	48 8b 12             	mov    (%rdx),%rdx
  401842:	8b 4d f0             	mov    -0x10(%rbp),%ecx
  401845:	48 63 c9             	movslq %ecx,%rcx
  401848:	48 c1 e1 03          	shl    $0x3,%rcx
  40184c:	48 01 ca             	add    %rcx,%rdx
  40184f:	48 8b 12             	mov    (%rdx),%rdx
  401852:	8b 4d f4             	mov    -0xc(%rbp),%ecx
  401855:	48 63 c9             	movslq %ecx,%rcx
  401858:	48 c1 e1 02          	shl    $0x2,%rcx
  40185c:	48 01 d1             	add    %rdx,%rcx
  40185f:	8b 55 f0             	mov    -0x10(%rbp),%edx
  401862:	48 63 f2             	movslq %edx,%rsi
  401865:	48 63 d0             	movslq %eax,%rdx
  401868:	48 0f af d6          	imul   %rsi,%rdx
  40186c:	48 8d 34 95 00 00 00 	lea    0x0(,%rdx,4),%rsi
  401873:	00 
  401874:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
  401878:	48 01 d6             	add    %rdx,%rsi
  40187b:	8b 55 f4             	mov    -0xc(%rbp),%edx
  40187e:	48 63 d2             	movslq %edx,%rdx
  401881:	f3 0f 10 04 96       	movss  (%rsi,%rdx,4),%xmm0
  401886:	f3 0f 11 01          	movss  %xmm0,(%rcx)
  40188a:	83 45 f4 01          	addl   $0x1,-0xc(%rbp)
  40188e:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  401892:	8b 52 0c             	mov    0xc(%rdx),%edx
  401895:	3b 55 f4             	cmp    -0xc(%rbp),%edx
  401898:	7f a1                	jg     40183b <copyMatrix+0x73>
  40189a:	83 45 f0 01          	addl   $0x1,-0x10(%rbp)
  40189e:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  4018a2:	8b 52 08             	mov    0x8(%rdx),%edx
  4018a5:	3b 55 f0             	cmp    -0x10(%rbp),%edx
  4018a8:	7f 88                	jg     401832 <copyMatrix+0x6a>
  4018aa:	c9                   	leaveq 
  4018ab:	c3                   	retq   

00000000004018ac <findTotalDigits>:
  4018ac:	55                   	push   %rbp
  4018ad:	48 89 e5             	mov    %rsp,%rbp
  4018b0:	89 7d ec             	mov    %edi,-0x14(%rbp)
  4018b3:	c7 45 f8 01 00 00 00 	movl   $0x1,-0x8(%rbp)
  4018ba:	c7 45 fc 0a 00 00 00 	movl   $0xa,-0x4(%rbp)
  4018c1:	eb 13                	jmp    4018d6 <findTotalDigits+0x2a>
  4018c3:	83 45 f8 01          	addl   $0x1,-0x8(%rbp)
  4018c7:	8b 55 fc             	mov    -0x4(%rbp),%edx
  4018ca:	89 d0                	mov    %edx,%eax
  4018cc:	c1 e0 02             	shl    $0x2,%eax
  4018cf:	01 d0                	add    %edx,%eax
  4018d1:	01 c0                	add    %eax,%eax
  4018d3:	89 45 fc             	mov    %eax,-0x4(%rbp)
  4018d6:	8b 45 ec             	mov    -0x14(%rbp),%eax
  4018d9:	99                   	cltd   
  4018da:	89 d0                	mov    %edx,%eax
  4018dc:	33 45 ec             	xor    -0x14(%rbp),%eax
  4018df:	29 d0                	sub    %edx,%eax
  4018e1:	3b 45 fc             	cmp    -0x4(%rbp),%eax
  4018e4:	7d dd                	jge    4018c3 <findTotalDigits+0x17>
  4018e6:	83 7d ec 00          	cmpl   $0x0,-0x14(%rbp)
  4018ea:	79 04                	jns    4018f0 <findTotalDigits+0x44>
  4018ec:	83 45 f8 01          	addl   $0x1,-0x8(%rbp)
  4018f0:	8b 45 f8             	mov    -0x8(%rbp),%eax
  4018f3:	5d                   	pop    %rbp
  4018f4:	c3                   	retq   

00000000004018f5 <getPadding>:
  4018f5:	55                   	push   %rbp
  4018f6:	48 89 e5             	mov    %rsp,%rbp
  4018f9:	48 83 ec 30          	sub    $0x30,%rsp
  4018fd:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  401901:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  401905:	8b 40 0c             	mov    0xc(%rax),%eax
  401908:	48 98                	cltq   
  40190a:	be 04 00 00 00       	mov    $0x4,%esi
  40190f:	48 89 c7             	mov    %rax,%rdi
  401912:	e8 59 ed ff ff       	callq  400670 <calloc@plt>
  401917:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  40191b:	c7 45 ec 00 00 00 00 	movl   $0x0,-0x14(%rbp)
  401922:	e9 87 00 00 00       	jmpq   4019ae <getPadding+0xb9>
  401927:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%rbp)
  40192e:	eb 6e                	jmp    40199e <getPadding+0xa9>
  401930:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  401934:	48 8b 00             	mov    (%rax),%rax
  401937:	8b 55 f0             	mov    -0x10(%rbp),%edx
  40193a:	48 63 d2             	movslq %edx,%rdx
  40193d:	48 c1 e2 03          	shl    $0x3,%rdx
  401941:	48 01 d0             	add    %rdx,%rax
  401944:	48 8b 00             	mov    (%rax),%rax
  401947:	8b 55 ec             	mov    -0x14(%rbp),%edx
  40194a:	48 63 d2             	movslq %edx,%rdx
  40194d:	48 c1 e2 02          	shl    $0x2,%rdx
  401951:	48 01 d0             	add    %rdx,%rax
  401954:	f3 0f 10 00          	movss  (%rax),%xmm0
  401958:	f3 0f 2c c0          	cvttss2si %xmm0,%eax
  40195c:	89 c7                	mov    %eax,%edi
  40195e:	e8 49 ff ff ff       	callq  4018ac <findTotalDigits>
  401963:	89 45 f4             	mov    %eax,-0xc(%rbp)
  401966:	8b 45 ec             	mov    -0x14(%rbp),%eax
  401969:	48 98                	cltq   
  40196b:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
  401972:	00 
  401973:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  401977:	48 01 d0             	add    %rdx,%rax
  40197a:	8b 00                	mov    (%rax),%eax
  40197c:	3b 45 f4             	cmp    -0xc(%rbp),%eax
  40197f:	7d 19                	jge    40199a <getPadding+0xa5>
  401981:	8b 45 ec             	mov    -0x14(%rbp),%eax
  401984:	48 98                	cltq   
  401986:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
  40198d:	00 
  40198e:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  401992:	48 01 c2             	add    %rax,%rdx
  401995:	8b 45 f4             	mov    -0xc(%rbp),%eax
  401998:	89 02                	mov    %eax,(%rdx)
  40199a:	83 45 f0 01          	addl   $0x1,-0x10(%rbp)
  40199e:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  4019a2:	8b 40 08             	mov    0x8(%rax),%eax
  4019a5:	3b 45 f0             	cmp    -0x10(%rbp),%eax
  4019a8:	7f 86                	jg     401930 <getPadding+0x3b>
  4019aa:	83 45 ec 01          	addl   $0x1,-0x14(%rbp)
  4019ae:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  4019b2:	8b 40 0c             	mov    0xc(%rax),%eax
  4019b5:	3b 45 ec             	cmp    -0x14(%rbp),%eax
  4019b8:	0f 8f 69 ff ff ff    	jg     401927 <getPadding+0x32>
  4019be:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  4019c2:	c9                   	leaveq 
  4019c3:	c3                   	retq   

00000000004019c4 <findTotalDP>:
  4019c4:	55                   	push   %rbp
  4019c5:	48 89 e5             	mov    %rsp,%rbp
  4019c8:	f3 0f 11 45 ec       	movss  %xmm0,-0x14(%rbp)
  4019cd:	c7 45 f8 00 00 00 00 	movl   $0x0,-0x8(%rbp)
  4019d4:	66 0f ef c0          	pxor   %xmm0,%xmm0
  4019d8:	0f 2e 45 ec          	ucomiss -0x14(%rbp),%xmm0
  4019dc:	7a 12                	jp     4019f0 <findTotalDP+0x2c>
  4019de:	66 0f ef c0          	pxor   %xmm0,%xmm0
  4019e2:	0f 2e 45 ec          	ucomiss -0x14(%rbp),%xmm0
  4019e6:	75 08                	jne    4019f0 <findTotalDP+0x2c>
  4019e8:	8b 45 f8             	mov    -0x8(%rbp),%eax
  4019eb:	e9 99 00 00 00       	jmpq   401a89 <findTotalDP+0xc5>
  4019f0:	66 0f ef c0          	pxor   %xmm0,%xmm0
  4019f4:	0f 2e 45 ec          	ucomiss -0x14(%rbp),%xmm0
  4019f8:	76 15                	jbe    401a0f <findTotalDP+0x4b>
  4019fa:	f3 0f 10 4d ec       	movss  -0x14(%rbp),%xmm1
  4019ff:	f3 0f 10 05 19 0a 00 	movss  0xa19(%rip),%xmm0        # 402420 <_IO_stdin_used+0x2c0>
  401a06:	00 
  401a07:	0f 57 c1             	xorps  %xmm1,%xmm0
  401a0a:	f3 0f 11 45 ec       	movss  %xmm0,-0x14(%rbp)
  401a0f:	eb 1a                	jmp    401a2b <findTotalDP+0x67>
  401a11:	f3 0f 10 4d ec       	movss  -0x14(%rbp),%xmm1
  401a16:	f3 0f 10 05 12 0a 00 	movss  0xa12(%rip),%xmm0        # 402430 <_IO_stdin_used+0x2d0>
  401a1d:	00 
  401a1e:	f3 0f 59 c1          	mulss  %xmm1,%xmm0
  401a22:	f3 0f 11 45 ec       	movss  %xmm0,-0x14(%rbp)
  401a27:	83 45 f8 01          	addl   $0x1,-0x8(%rbp)
  401a2b:	f3 0f 10 05 01 0a 00 	movss  0xa01(%rip),%xmm0        # 402434 <_IO_stdin_used+0x2d4>
  401a32:	00 
  401a33:	0f 2e 45 ec          	ucomiss -0x14(%rbp),%xmm0
  401a37:	77 d8                	ja     401a11 <findTotalDP+0x4d>
  401a39:	f3 0f 10 45 ec       	movss  -0x14(%rbp),%xmm0
  401a3e:	f3 0f 2c c0          	cvttss2si %xmm0,%eax
  401a42:	66 0f ef c0          	pxor   %xmm0,%xmm0
  401a46:	f3 0f 2a c0          	cvtsi2ss %eax,%xmm0
  401a4a:	f3 0f 5c 45 ec       	subss  -0x14(%rbp),%xmm0
  401a4f:	f3 0f 11 45 fc       	movss  %xmm0,-0x4(%rbp)
  401a54:	66 0f ef c0          	pxor   %xmm0,%xmm0
  401a58:	0f 2e 45 fc          	ucomiss -0x4(%rbp),%xmm0
  401a5c:	76 15                	jbe    401a73 <findTotalDP+0xaf>
  401a5e:	f3 0f 10 4d fc       	movss  -0x4(%rbp),%xmm1
  401a63:	f3 0f 10 05 b5 09 00 	movss  0x9b5(%rip),%xmm0        # 402420 <_IO_stdin_used+0x2c0>
  401a6a:	00 
  401a6b:	0f 57 c1             	xorps  %xmm1,%xmm0
  401a6e:	f3 0f 11 45 fc       	movss  %xmm0,-0x4(%rbp)
  401a73:	f3 0f 5a 45 fc       	cvtss2sd -0x4(%rbp),%xmm0
  401a78:	66 0f 2e 05 b8 09 00 	ucomisd 0x9b8(%rip),%xmm0        # 402438 <_IO_stdin_used+0x2d8>
  401a7f:	00 
  401a80:	76 04                	jbe    401a86 <findTotalDP+0xc2>
  401a82:	83 45 f8 01          	addl   $0x1,-0x8(%rbp)
  401a86:	8b 45 f8             	mov    -0x8(%rbp),%eax
  401a89:	5d                   	pop    %rbp
  401a8a:	c3                   	retq   

0000000000401a8b <getDP>:
  401a8b:	55                   	push   %rbp
  401a8c:	48 89 e5             	mov    %rsp,%rbp
  401a8f:	48 83 ec 30          	sub    $0x30,%rsp
  401a93:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  401a97:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  401a9b:	8b 40 0c             	mov    0xc(%rax),%eax
  401a9e:	48 98                	cltq   
  401aa0:	be 04 00 00 00       	mov    $0x4,%esi
  401aa5:	48 89 c7             	mov    %rax,%rdi
  401aa8:	e8 c3 eb ff ff       	callq  400670 <calloc@plt>
  401aad:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  401ab1:	c7 45 ec 00 00 00 00 	movl   $0x0,-0x14(%rbp)
  401ab8:	e9 87 00 00 00       	jmpq   401b44 <getDP+0xb9>
  401abd:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%rbp)
  401ac4:	eb 6e                	jmp    401b34 <getDP+0xa9>
  401ac6:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  401aca:	48 8b 00             	mov    (%rax),%rax
  401acd:	8b 55 f0             	mov    -0x10(%rbp),%edx
  401ad0:	48 63 d2             	movslq %edx,%rdx
  401ad3:	48 c1 e2 03          	shl    $0x3,%rdx
  401ad7:	48 01 d0             	add    %rdx,%rax
  401ada:	48 8b 00             	mov    (%rax),%rax
  401add:	8b 55 ec             	mov    -0x14(%rbp),%edx
  401ae0:	48 63 d2             	movslq %edx,%rdx
  401ae3:	48 c1 e2 02          	shl    $0x2,%rdx
  401ae7:	48 01 d0             	add    %rdx,%rax
  401aea:	8b 00                	mov    (%rax),%eax
  401aec:	89 45 d4             	mov    %eax,-0x2c(%rbp)
  401aef:	f3 0f 10 45 d4       	movss  -0x2c(%rbp),%xmm0
  401af4:	e8 cb fe ff ff       	callq  4019c4 <findTotalDP>
  401af9:	89 45 f4             	mov    %eax,-0xc(%rbp)
  401afc:	8b 45 ec             	mov    -0x14(%rbp),%eax
  401aff:	48 98                	cltq   
  401b01:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
  401b08:	00 
  401b09:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  401b0d:	48 01 d0             	add    %rdx,%rax
  401b10:	8b 00                	mov    (%rax),%eax
  401b12:	3b 45 f4             	cmp    -0xc(%rbp),%eax
  401b15:	7d 19                	jge    401b30 <getDP+0xa5>
  401b17:	8b 45 ec             	mov    -0x14(%rbp),%eax
  401b1a:	48 98                	cltq   
  401b1c:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
  401b23:	00 
  401b24:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  401b28:	48 01 c2             	add    %rax,%rdx
  401b2b:	8b 45 f4             	mov    -0xc(%rbp),%eax
  401b2e:	89 02                	mov    %eax,(%rdx)
  401b30:	83 45 f0 01          	addl   $0x1,-0x10(%rbp)
  401b34:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  401b38:	8b 40 08             	mov    0x8(%rax),%eax
  401b3b:	3b 45 f0             	cmp    -0x10(%rbp),%eax
  401b3e:	7f 86                	jg     401ac6 <getDP+0x3b>
  401b40:	83 45 ec 01          	addl   $0x1,-0x14(%rbp)
  401b44:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  401b48:	8b 40 0c             	mov    0xc(%rax),%eax
  401b4b:	3b 45 ec             	cmp    -0x14(%rbp),%eax
  401b4e:	0f 8f 69 ff ff ff    	jg     401abd <getDP+0x32>
  401b54:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  401b58:	c9                   	leaveq 
  401b59:	c3                   	retq   

0000000000401b5a <showMatrix>:
  401b5a:	55                   	push   %rbp
  401b5b:	48 89 e5             	mov    %rsp,%rbp
  401b5e:	48 83 ec 30          	sub    $0x30,%rsp
  401b62:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  401b66:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  401b6a:	48 89 c7             	mov    %rax,%rdi
  401b6d:	e8 83 fd ff ff       	callq  4018f5 <getPadding>
  401b72:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
  401b76:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  401b7a:	48 89 c7             	mov    %rax,%rdi
  401b7d:	e8 09 ff ff ff       	callq  401a8b <getDP>
  401b82:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  401b86:	c7 45 e4 00 00 00 00 	movl   $0x0,-0x1c(%rbp)
  401b8d:	e9 c7 00 00 00       	jmpq   401c59 <showMatrix+0xff>
  401b92:	bf 9a 23 40 00       	mov    $0x40239a,%edi
  401b97:	b8 00 00 00 00       	mov    $0x0,%eax
  401b9c:	e8 af ea ff ff       	callq  400650 <printf@plt>
  401ba1:	c7 45 e8 00 00 00 00 	movl   $0x0,-0x18(%rbp)
  401ba8:	e9 8e 00 00 00       	jmpq   401c3b <showMatrix+0xe1>
  401bad:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  401bb1:	8b 40 10             	mov    0x10(%rax),%eax
  401bb4:	3b 45 e8             	cmp    -0x18(%rbp),%eax
  401bb7:	75 0f                	jne    401bc8 <showMatrix+0x6e>
  401bb9:	bf 9a 23 40 00       	mov    $0x40239a,%edi
  401bbe:	b8 00 00 00 00       	mov    $0x0,%eax
  401bc3:	e8 88 ea ff ff       	callq  400650 <printf@plt>
  401bc8:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  401bcc:	48 8b 00             	mov    (%rax),%rax
  401bcf:	8b 55 e4             	mov    -0x1c(%rbp),%edx
  401bd2:	48 63 d2             	movslq %edx,%rdx
  401bd5:	48 c1 e2 03          	shl    $0x3,%rdx
  401bd9:	48 01 d0             	add    %rdx,%rax
  401bdc:	48 8b 00             	mov    (%rax),%rax
  401bdf:	8b 55 e8             	mov    -0x18(%rbp),%edx
  401be2:	48 63 d2             	movslq %edx,%rdx
  401be5:	48 c1 e2 02          	shl    $0x2,%rdx
  401be9:	48 01 d0             	add    %rdx,%rax
  401bec:	f3 0f 10 00          	movss  (%rax),%xmm0
  401bf0:	f3 0f 11 45 ec       	movss  %xmm0,-0x14(%rbp)
  401bf5:	f3 0f 5a 45 ec       	cvtss2sd -0x14(%rbp),%xmm0
  401bfa:	8b 45 e8             	mov    -0x18(%rbp),%eax
  401bfd:	48 98                	cltq   
  401bff:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
  401c06:	00 
  401c07:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  401c0b:	48 01 d0             	add    %rdx,%rax
  401c0e:	8b 10                	mov    (%rax),%edx
  401c10:	8b 45 e8             	mov    -0x18(%rbp),%eax
  401c13:	48 98                	cltq   
  401c15:	48 8d 0c 85 00 00 00 	lea    0x0(,%rax,4),%rcx
  401c1c:	00 
  401c1d:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  401c21:	48 01 c8             	add    %rcx,%rax
  401c24:	8b 00                	mov    (%rax),%eax
  401c26:	89 c6                	mov    %eax,%esi
  401c28:	bf 9d 23 40 00       	mov    $0x40239d,%edi
  401c2d:	b8 01 00 00 00       	mov    $0x1,%eax
  401c32:	e8 19 ea ff ff       	callq  400650 <printf@plt>
  401c37:	83 45 e8 01          	addl   $0x1,-0x18(%rbp)
  401c3b:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  401c3f:	8b 40 0c             	mov    0xc(%rax),%eax
  401c42:	3b 45 e8             	cmp    -0x18(%rbp),%eax
  401c45:	0f 8f 62 ff ff ff    	jg     401bad <showMatrix+0x53>
  401c4b:	bf a5 23 40 00       	mov    $0x4023a5,%edi
  401c50:	e8 db e9 ff ff       	callq  400630 <puts@plt>
  401c55:	83 45 e4 01          	addl   $0x1,-0x1c(%rbp)
  401c59:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  401c5d:	8b 40 08             	mov    0x8(%rax),%eax
  401c60:	3b 45 e4             	cmp    -0x1c(%rbp),%eax
  401c63:	0f 8f 29 ff ff ff    	jg     401b92 <showMatrix+0x38>
  401c69:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  401c6d:	48 89 c7             	mov    %rax,%rdi
  401c70:	e8 ab e9 ff ff       	callq  400620 <free@plt>
  401c75:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  401c79:	48 89 c7             	mov    %rax,%rdi
  401c7c:	e8 9f e9 ff ff       	callq  400620 <free@plt>
  401c81:	90                   	nop
  401c82:	c9                   	leaveq 
  401c83:	c3                   	retq   

0000000000401c84 <freeMatrix>:
  401c84:	55                   	push   %rbp
  401c85:	48 89 e5             	mov    %rsp,%rbp
  401c88:	48 83 ec 20          	sub    $0x20,%rsp
  401c8c:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  401c90:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  401c97:	eb 23                	jmp    401cbc <freeMatrix+0x38>
  401c99:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  401c9d:	48 8b 00             	mov    (%rax),%rax
  401ca0:	8b 55 fc             	mov    -0x4(%rbp),%edx
  401ca3:	48 63 d2             	movslq %edx,%rdx
  401ca6:	48 c1 e2 03          	shl    $0x3,%rdx
  401caa:	48 01 d0             	add    %rdx,%rax
  401cad:	48 8b 00             	mov    (%rax),%rax
  401cb0:	48 89 c7             	mov    %rax,%rdi
  401cb3:	e8 68 e9 ff ff       	callq  400620 <free@plt>
  401cb8:	83 45 fc 01          	addl   $0x1,-0x4(%rbp)
  401cbc:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  401cc0:	8b 40 08             	mov    0x8(%rax),%eax
  401cc3:	3b 45 fc             	cmp    -0x4(%rbp),%eax
  401cc6:	7f d1                	jg     401c99 <freeMatrix+0x15>
  401cc8:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  401ccc:	48 8b 00             	mov    (%rax),%rax
  401ccf:	48 89 c7             	mov    %rax,%rdi
  401cd2:	e8 49 e9 ff ff       	callq  400620 <free@plt>
  401cd7:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  401cdb:	48 89 c7             	mov    %rax,%rdi
  401cde:	e8 3d e9 ff ff       	callq  400620 <free@plt>
  401ce3:	90                   	nop
  401ce4:	c9                   	leaveq 
  401ce5:	c3                   	retq   

0000000000401ce6 <findDeterminant>:
  401ce6:	55                   	push   %rbp
  401ce7:	48 89 e5             	mov    %rsp,%rbp
  401cea:	48 83 ec 40          	sub    $0x40,%rsp
  401cee:	48 89 7d c8          	mov    %rdi,-0x38(%rbp)
  401cf2:	c7 45 dc 00 00 00 00 	movl   $0x0,-0x24(%rbp)
  401cf9:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  401cfd:	8b 50 08             	mov    0x8(%rax),%edx
  401d00:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  401d04:	8b 40 0c             	mov    0xc(%rax),%eax
  401d07:	39 c2                	cmp    %eax,%edx
  401d09:	75 0c                	jne    401d17 <findDeterminant+0x31>
  401d0b:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  401d0f:	8b 40 08             	mov    0x8(%rax),%eax
  401d12:	83 f8 01             	cmp    $0x1,%eax
  401d15:	7f 1c                	jg     401d33 <findDeterminant+0x4d>
  401d17:	ba 00 00 00 00       	mov    $0x0,%edx
  401d1c:	be a8 23 40 00       	mov    $0x4023a8,%esi
  401d21:	bf d0 23 40 00       	mov    $0x4023d0,%edi
  401d26:	e8 36 03 00 00       	callq  402061 <printError>
  401d2b:	8b 45 dc             	mov    -0x24(%rbp),%eax
  401d2e:	e9 cd 01 00 00       	jmpq   401f00 <findDeterminant+0x21a>
  401d33:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  401d37:	8b 40 08             	mov    0x8(%rax),%eax
  401d3a:	89 45 f4             	mov    %eax,-0xc(%rbp)
  401d3d:	83 7d f4 02          	cmpl   $0x2,-0xc(%rbp)
  401d41:	75 73                	jne    401db6 <findDeterminant+0xd0>
  401d43:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  401d47:	48 8b 00             	mov    (%rax),%rax
  401d4a:	48 8b 00             	mov    (%rax),%rax
  401d4d:	f3 0f 10 08          	movss  (%rax),%xmm1
  401d51:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  401d55:	48 8b 00             	mov    (%rax),%rax
  401d58:	48 83 c0 08          	add    $0x8,%rax
  401d5c:	48 8b 00             	mov    (%rax),%rax
  401d5f:	48 83 c0 04          	add    $0x4,%rax
  401d63:	f3 0f 10 00          	movss  (%rax),%xmm0
  401d67:	f3 0f 59 c1          	mulss  %xmm1,%xmm0
  401d6b:	f3 0f 2c c0          	cvttss2si %xmm0,%eax
  401d6f:	89 45 dc             	mov    %eax,-0x24(%rbp)
  401d72:	66 0f ef c0          	pxor   %xmm0,%xmm0
  401d76:	f3 0f 2a 45 dc       	cvtsi2ssl -0x24(%rbp),%xmm0
  401d7b:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  401d7f:	48 8b 00             	mov    (%rax),%rax
  401d82:	48 8b 00             	mov    (%rax),%rax
  401d85:	48 83 c0 04          	add    $0x4,%rax
  401d89:	f3 0f 10 10          	movss  (%rax),%xmm2
  401d8d:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  401d91:	48 8b 00             	mov    (%rax),%rax
  401d94:	48 83 c0 08          	add    $0x8,%rax
  401d98:	48 8b 00             	mov    (%rax),%rax
  401d9b:	f3 0f 10 08          	movss  (%rax),%xmm1
  401d9f:	f3 0f 59 ca          	mulss  %xmm2,%xmm1
  401da3:	f3 0f 5c c1          	subss  %xmm1,%xmm0
  401da7:	f3 0f 2c c0          	cvttss2si %xmm0,%eax
  401dab:	89 45 dc             	mov    %eax,-0x24(%rbp)
  401dae:	8b 45 dc             	mov    -0x24(%rbp),%eax
  401db1:	e9 4a 01 00 00       	jmpq   401f00 <findDeterminant+0x21a>
  401db6:	c7 45 e0 00 00 00 00 	movl   $0x0,-0x20(%rbp)
  401dbd:	c7 45 e4 01 00 00 00 	movl   $0x1,-0x1c(%rbp)
  401dc4:	e9 28 01 00 00       	jmpq   401ef1 <findDeterminant+0x20b>
  401dc9:	8b 45 f4             	mov    -0xc(%rbp),%eax
  401dcc:	8d 50 ff             	lea    -0x1(%rax),%edx
  401dcf:	8b 45 f4             	mov    -0xc(%rbp),%eax
  401dd2:	83 e8 01             	sub    $0x1,%eax
  401dd5:	89 d6                	mov    %edx,%esi
  401dd7:	89 c7                	mov    %eax,%edi
  401dd9:	e8 45 f9 ff ff       	callq  401723 <createMatrix>
  401dde:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  401de2:	c7 45 e8 00 00 00 00 	movl   $0x0,-0x18(%rbp)
  401de9:	e9 87 00 00 00       	jmpq   401e75 <findDeterminant+0x18f>
  401dee:	c7 45 ec 00 00 00 00 	movl   $0x0,-0x14(%rbp)
  401df5:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%rbp)
  401dfc:	eb 6b                	jmp    401e69 <findDeterminant+0x183>
  401dfe:	8b 45 ec             	mov    -0x14(%rbp),%eax
  401e01:	3b 45 e0             	cmp    -0x20(%rbp),%eax
  401e04:	74 58                	je     401e5e <findDeterminant+0x178>
  401e06:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  401e0a:	48 8b 00             	mov    (%rax),%rax
  401e0d:	8b 55 e8             	mov    -0x18(%rbp),%edx
  401e10:	48 63 d2             	movslq %edx,%rdx
  401e13:	48 c1 e2 03          	shl    $0x3,%rdx
  401e17:	48 01 d0             	add    %rdx,%rax
  401e1a:	48 8b 10             	mov    (%rax),%rdx
  401e1d:	8b 45 ec             	mov    -0x14(%rbp),%eax
  401e20:	2b 45 f0             	sub    -0x10(%rbp),%eax
  401e23:	48 98                	cltq   
  401e25:	48 c1 e0 02          	shl    $0x2,%rax
  401e29:	48 01 c2             	add    %rax,%rdx
  401e2c:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  401e30:	48 8b 00             	mov    (%rax),%rax
  401e33:	8b 4d e8             	mov    -0x18(%rbp),%ecx
  401e36:	48 63 c9             	movslq %ecx,%rcx
  401e39:	48 83 c1 01          	add    $0x1,%rcx
  401e3d:	48 c1 e1 03          	shl    $0x3,%rcx
  401e41:	48 01 c8             	add    %rcx,%rax
  401e44:	48 8b 00             	mov    (%rax),%rax
  401e47:	8b 4d ec             	mov    -0x14(%rbp),%ecx
  401e4a:	48 63 c9             	movslq %ecx,%rcx
  401e4d:	48 c1 e1 02          	shl    $0x2,%rcx
  401e51:	48 01 c8             	add    %rcx,%rax
  401e54:	f3 0f 10 00          	movss  (%rax),%xmm0
  401e58:	f3 0f 11 02          	movss  %xmm0,(%rdx)
  401e5c:	eb 07                	jmp    401e65 <findDeterminant+0x17f>
  401e5e:	c7 45 f0 01 00 00 00 	movl   $0x1,-0x10(%rbp)
  401e65:	83 45 ec 01          	addl   $0x1,-0x14(%rbp)
  401e69:	8b 45 ec             	mov    -0x14(%rbp),%eax
  401e6c:	3b 45 f4             	cmp    -0xc(%rbp),%eax
  401e6f:	7c 8d                	jl     401dfe <findDeterminant+0x118>
  401e71:	83 45 e8 01          	addl   $0x1,-0x18(%rbp)
  401e75:	8b 45 f4             	mov    -0xc(%rbp),%eax
  401e78:	83 e8 01             	sub    $0x1,%eax
  401e7b:	3b 45 e8             	cmp    -0x18(%rbp),%eax
  401e7e:	0f 8f 6a ff ff ff    	jg     401dee <findDeterminant+0x108>
  401e84:	66 0f ef c0          	pxor   %xmm0,%xmm0
  401e88:	f3 0f 2a 45 e4       	cvtsi2ssl -0x1c(%rbp),%xmm0
  401e8d:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  401e91:	48 8b 00             	mov    (%rax),%rax
  401e94:	48 8b 00             	mov    (%rax),%rax
  401e97:	8b 55 e0             	mov    -0x20(%rbp),%edx
  401e9a:	48 63 d2             	movslq %edx,%rdx
  401e9d:	48 c1 e2 02          	shl    $0x2,%rdx
  401ea1:	48 01 d0             	add    %rdx,%rax
  401ea4:	f3 0f 10 08          	movss  (%rax),%xmm1
  401ea8:	f3 0f 59 c1          	mulss  %xmm1,%xmm0
  401eac:	f3 0f 11 45 c4       	movss  %xmm0,-0x3c(%rbp)
  401eb1:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  401eb5:	48 89 c7             	mov    %rax,%rdi
  401eb8:	e8 29 fe ff ff       	callq  401ce6 <findDeterminant>
  401ebd:	66 0f ef c0          	pxor   %xmm0,%xmm0
  401ec1:	f3 0f 2a c0          	cvtsi2ss %eax,%xmm0
  401ec5:	f3 0f 59 45 c4       	mulss  -0x3c(%rbp),%xmm0
  401eca:	66 0f ef c9          	pxor   %xmm1,%xmm1
  401ece:	f3 0f 2a 4d dc       	cvtsi2ssl -0x24(%rbp),%xmm1
  401ed3:	f3 0f 58 c1          	addss  %xmm1,%xmm0
  401ed7:	f3 0f 2c c0          	cvttss2si %xmm0,%eax
  401edb:	89 45 dc             	mov    %eax,-0x24(%rbp)
  401ede:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  401ee2:	48 89 c7             	mov    %rax,%rdi
  401ee5:	e8 9a fd ff ff       	callq  401c84 <freeMatrix>
  401eea:	83 45 e0 01          	addl   $0x1,-0x20(%rbp)
  401eee:	f7 5d e4             	negl   -0x1c(%rbp)
  401ef1:	8b 45 e0             	mov    -0x20(%rbp),%eax
  401ef4:	3b 45 f4             	cmp    -0xc(%rbp),%eax
  401ef7:	0f 8c cc fe ff ff    	jl     401dc9 <findDeterminant+0xe3>
  401efd:	8b 45 dc             	mov    -0x24(%rbp),%eax
  401f00:	c9                   	leaveq 
  401f01:	c3                   	retq   

0000000000401f02 <multiplyMatrix>:
  401f02:	55                   	push   %rbp
  401f03:	48 89 e5             	mov    %rsp,%rbp
  401f06:	48 83 ec 30          	sub    $0x30,%rsp
  401f0a:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  401f0e:	48 89 75 d0          	mov    %rsi,-0x30(%rbp)
  401f12:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  401f16:	8b 50 0c             	mov    0xc(%rax),%edx
  401f19:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  401f1d:	8b 40 08             	mov    0x8(%rax),%eax
  401f20:	39 c2                	cmp    %eax,%edx
  401f22:	74 14                	je     401f38 <multiplyMatrix+0x36>
  401f24:	ba 01 00 00 00       	mov    $0x1,%edx
  401f29:	be e4 23 40 00       	mov    $0x4023e4,%esi
  401f2e:	bf fe 23 40 00       	mov    $0x4023fe,%edi
  401f33:	e8 29 01 00 00       	callq  402061 <printError>
  401f38:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  401f3c:	8b 50 0c             	mov    0xc(%rax),%edx
  401f3f:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  401f43:	8b 40 08             	mov    0x8(%rax),%eax
  401f46:	89 d6                	mov    %edx,%esi
  401f48:	89 c7                	mov    %eax,%edi
  401f4a:	e8 d4 f7 ff ff       	callq  401723 <createMatrix>
  401f4f:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  401f53:	c7 45 ec 00 00 00 00 	movl   $0x0,-0x14(%rbp)
  401f5a:	e9 ec 00 00 00       	jmpq   40204b <multiplyMatrix+0x149>
  401f5f:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%rbp)
  401f66:	e9 cc 00 00 00       	jmpq   402037 <multiplyMatrix+0x135>
  401f6b:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%rbp)
  401f72:	e9 ac 00 00 00       	jmpq   402023 <multiplyMatrix+0x121>
  401f77:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  401f7b:	48 8b 00             	mov    (%rax),%rax
  401f7e:	8b 55 ec             	mov    -0x14(%rbp),%edx
  401f81:	48 63 d2             	movslq %edx,%rdx
  401f84:	48 c1 e2 03          	shl    $0x3,%rdx
  401f88:	48 01 d0             	add    %rdx,%rax
  401f8b:	48 8b 00             	mov    (%rax),%rax
  401f8e:	8b 55 f0             	mov    -0x10(%rbp),%edx
  401f91:	48 63 d2             	movslq %edx,%rdx
  401f94:	48 c1 e2 02          	shl    $0x2,%rdx
  401f98:	48 01 c2             	add    %rax,%rdx
  401f9b:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  401f9f:	48 8b 00             	mov    (%rax),%rax
  401fa2:	8b 4d ec             	mov    -0x14(%rbp),%ecx
  401fa5:	48 63 c9             	movslq %ecx,%rcx
  401fa8:	48 c1 e1 03          	shl    $0x3,%rcx
  401fac:	48 01 c8             	add    %rcx,%rax
  401faf:	48 8b 00             	mov    (%rax),%rax
  401fb2:	8b 4d f0             	mov    -0x10(%rbp),%ecx
  401fb5:	48 63 c9             	movslq %ecx,%rcx
  401fb8:	48 c1 e1 02          	shl    $0x2,%rcx
  401fbc:	48 01 c8             	add    %rcx,%rax
  401fbf:	f3 0f 10 08          	movss  (%rax),%xmm1
  401fc3:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  401fc7:	48 8b 00             	mov    (%rax),%rax
  401fca:	8b 4d ec             	mov    -0x14(%rbp),%ecx
  401fcd:	48 63 c9             	movslq %ecx,%rcx
  401fd0:	48 c1 e1 03          	shl    $0x3,%rcx
  401fd4:	48 01 c8             	add    %rcx,%rax
  401fd7:	48 8b 00             	mov    (%rax),%rax
  401fda:	8b 4d f4             	mov    -0xc(%rbp),%ecx
  401fdd:	48 63 c9             	movslq %ecx,%rcx
  401fe0:	48 c1 e1 02          	shl    $0x2,%rcx
  401fe4:	48 01 c8             	add    %rcx,%rax
  401fe7:	f3 0f 10 10          	movss  (%rax),%xmm2
  401feb:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  401fef:	48 8b 00             	mov    (%rax),%rax
  401ff2:	8b 4d f4             	mov    -0xc(%rbp),%ecx
  401ff5:	48 63 c9             	movslq %ecx,%rcx
  401ff8:	48 c1 e1 03          	shl    $0x3,%rcx
  401ffc:	48 01 c8             	add    %rcx,%rax
  401fff:	48 8b 00             	mov    (%rax),%rax
  402002:	8b 4d f0             	mov    -0x10(%rbp),%ecx
  402005:	48 63 c9             	movslq %ecx,%rcx
  402008:	48 c1 e1 02          	shl    $0x2,%rcx
  40200c:	48 01 c8             	add    %rcx,%rax
  40200f:	f3 0f 10 00          	movss  (%rax),%xmm0
  402013:	f3 0f 59 c2          	mulss  %xmm2,%xmm0
  402017:	f3 0f 58 c1          	addss  %xmm1,%xmm0
  40201b:	f3 0f 11 02          	movss  %xmm0,(%rdx)
  40201f:	83 45 f4 01          	addl   $0x1,-0xc(%rbp)
  402023:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  402027:	8b 40 0c             	mov    0xc(%rax),%eax
  40202a:	3b 45 f4             	cmp    -0xc(%rbp),%eax
  40202d:	0f 8f 44 ff ff ff    	jg     401f77 <multiplyMatrix+0x75>
  402033:	83 45 f0 01          	addl   $0x1,-0x10(%rbp)
  402037:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  40203b:	8b 40 0c             	mov    0xc(%rax),%eax
  40203e:	3b 45 f0             	cmp    -0x10(%rbp),%eax
  402041:	0f 8f 24 ff ff ff    	jg     401f6b <multiplyMatrix+0x69>
  402047:	83 45 ec 01          	addl   $0x1,-0x14(%rbp)
  40204b:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  40204f:	8b 40 08             	mov    0x8(%rax),%eax
  402052:	3b 45 ec             	cmp    -0x14(%rbp),%eax
  402055:	0f 8f 04 ff ff ff    	jg     401f5f <multiplyMatrix+0x5d>
  40205b:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  40205f:	c9                   	leaveq 
  402060:	c3                   	retq   

0000000000402061 <printError>:
  402061:	55                   	push   %rbp
  402062:	48 89 e5             	mov    %rsp,%rbp
  402065:	48 83 ec 20          	sub    $0x20,%rsp
  402069:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  40206d:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  402071:	89 55 ec             	mov    %edx,-0x14(%rbp)
  402074:	48 8b 05 05 10 20 00 	mov    0x201005(%rip),%rax        # 603080 <stderr@@GLIBC_2.2.5>
  40207b:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  40207f:	be 40 24 40 00       	mov    $0x402440,%esi
  402084:	48 89 c7             	mov    %rax,%rdi
  402087:	b8 00 00 00 00       	mov    $0x0,%eax
  40208c:	e8 ef e5 ff ff       	callq  400680 <fprintf@plt>
  402091:	48 8b 05 e8 0f 20 00 	mov    0x200fe8(%rip),%rax        # 603080 <stderr@@GLIBC_2.2.5>
  402098:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  40209c:	be 5c 24 40 00       	mov    $0x40245c,%esi
  4020a1:	48 89 c7             	mov    %rax,%rdi
  4020a4:	b8 00 00 00 00       	mov    $0x0,%eax
  4020a9:	e8 d2 e5 ff ff       	callq  400680 <fprintf@plt>
  4020ae:	83 7d ec 00          	cmpl   $0x0,-0x14(%rbp)
  4020b2:	74 28                	je     4020dc <printError+0x7b>
  4020b4:	48 8b 05 c5 0f 20 00 	mov    0x200fc5(%rip),%rax        # 603080 <stderr@@GLIBC_2.2.5>
  4020bb:	48 89 c1             	mov    %rax,%rcx
  4020be:	ba 1b 00 00 00       	mov    $0x1b,%edx
  4020c3:	be 01 00 00 00       	mov    $0x1,%esi
  4020c8:	bf 6e 24 40 00       	mov    $0x40246e,%edi
  4020cd:	e8 de e5 ff ff       	callq  4006b0 <fwrite@plt>
  4020d2:	bf 01 00 00 00       	mov    $0x1,%edi
  4020d7:	e8 c4 e5 ff ff       	callq  4006a0 <exit@plt>
  4020dc:	90                   	nop
  4020dd:	c9                   	leaveq 
  4020de:	c3                   	retq   
  4020df:	90                   	nop

00000000004020e0 <__libc_csu_init>:
  4020e0:	41 57                	push   %r15
  4020e2:	41 56                	push   %r14
  4020e4:	41 89 ff             	mov    %edi,%r15d
  4020e7:	41 55                	push   %r13
  4020e9:	41 54                	push   %r12
  4020eb:	4c 8d 25 1e 0d 20 00 	lea    0x200d1e(%rip),%r12        # 602e10 <__frame_dummy_init_array_entry>
  4020f2:	55                   	push   %rbp
  4020f3:	48 8d 2d 1e 0d 20 00 	lea    0x200d1e(%rip),%rbp        # 602e18 <__init_array_end>
  4020fa:	53                   	push   %rbx
  4020fb:	49 89 f6             	mov    %rsi,%r14
  4020fe:	49 89 d5             	mov    %rdx,%r13
  402101:	4c 29 e5             	sub    %r12,%rbp
  402104:	48 83 ec 08          	sub    $0x8,%rsp
  402108:	48 c1 fd 03          	sar    $0x3,%rbp
  40210c:	e8 d7 e4 ff ff       	callq  4005e8 <_init>
  402111:	48 85 ed             	test   %rbp,%rbp
  402114:	74 20                	je     402136 <__libc_csu_init+0x56>
  402116:	31 db                	xor    %ebx,%ebx
  402118:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  40211f:	00 
  402120:	4c 89 ea             	mov    %r13,%rdx
  402123:	4c 89 f6             	mov    %r14,%rsi
  402126:	44 89 ff             	mov    %r15d,%edi
  402129:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  40212d:	48 83 c3 01          	add    $0x1,%rbx
  402131:	48 39 eb             	cmp    %rbp,%rbx
  402134:	75 ea                	jne    402120 <__libc_csu_init+0x40>
  402136:	48 83 c4 08          	add    $0x8,%rsp
  40213a:	5b                   	pop    %rbx
  40213b:	5d                   	pop    %rbp
  40213c:	41 5c                	pop    %r12
  40213e:	41 5d                	pop    %r13
  402140:	41 5e                	pop    %r14
  402142:	41 5f                	pop    %r15
  402144:	c3                   	retq   
  402145:	90                   	nop
  402146:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40214d:	00 00 00 

0000000000402150 <__libc_csu_fini>:
  402150:	f3 c3                	repz retq 

Disassembly of section .fini:

0000000000402154 <_fini>:
  402154:	48 83 ec 08          	sub    $0x8,%rsp
  402158:	48 83 c4 08          	add    $0x8,%rsp
  40215c:	c3                   	retq   
