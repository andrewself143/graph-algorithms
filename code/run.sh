

for j in {256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144}
do
	for i in {1,2,3,4,5}
	do	
		#/usr/bin/time -f "$j %U" -o shell_sort4_uniform.csv --append ./main shell_sort4 $j
		#./main first_fit_decreasing $j >> first_fit_d2.csv
		./main $j >> cluster.csv
	done
done 
