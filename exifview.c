#include <stdio.h>
int main(int argc, char *argv[]){
	/*define struct for te first 20 bytes of image */
	struct first_tag {
		char start_marker[2];
		char APP1_marker[2];
		char APP1[2];
		char exif_string[4];
		char nul_zero[2];
		char endian[2];
		char version_num[2];
		int offset;
	};
	
	struct TIFF_tag {
		unsigned short ident;
		unsigned short type;
		int num_items;
		int val_offset;
	};
	
	/* declare the structs needed */
	struct first_tag tag;
	struct TIFF_tag tiff_array[3];
	struct TIFF_tag temp_tiff;
	
	/* declare identifiers for TIFF tags that we care about */
	short man_string = 0x010F;
	short cam_mod = 0x0110;
	short sub_block_address = 0x8769;
	unsigned short temp_ident, count;
	int i, j;
	char letter;
	char model_str[50];
	
	/* open file*/
	FILE *f = fopen(argv[1], "rb");
	if (f == NULL){
		printf("Input file does not exist.  Terminating program.\n\n");
		return 0;
	}
	
	 /*read first tag of .JPG file and get count */
	fread(&tag, sizeof(tag), 1, f);


	printf("First Marker: %#0X\n", tag.start_marker[0], tag.start_marker[1]);
	printf("APP1 Marker: %#0X\n", tag.APP1_marker[0], tag.APP1_marker[1]);
	printf("APP1 Block: %c %c\n", tag.APP1[0], tag.APP1[1]);
	printf("Exif String: %s\n", tag.exif_string);
	printf("Endianness: %s\n", tag.endian);
	
	/* get count */
	fread(&count, sizeof(unsigned short), 1, f);
	
	
	/*loop through and get TIFF tags we care about*/
	for(i = 0; i < count; i++){
		fread(&temp_tiff, sizeof(temp_tiff), 1, f);
		
		/*if tag identifier matches any we care about, save this tag to tiff_array*/
		temp_ident = temp_tiff.ident;
		printf("TIFF ident: %#x\n", temp_ident);
		
		if(temp_ident == man_string){
			/* Seek to file position 12 + offset */
			fseek(f, 12 + temp_tiff.val_offset, SEEK_SET);
			
			/*read each letter until NUL termintor */
			j=0;
			do {
				fread(&letter, sizeof(char), 1, f);
				model_str[j] = letter;
				j++;
			} while(letter != '\0');
			printf("Camera Model String: %s\n", model_str);
		} else if(temp_ident == cam_mod){
		} else if(temp_ident == sub_block_address){
		}
	}
	
	return 0;
}
