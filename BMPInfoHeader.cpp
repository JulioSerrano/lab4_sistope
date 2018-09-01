class BMPInfoHeader {

    uint16_t  type;
    int size;
    int reserved;
    int offset;
    int headersize;
    int width;
    int height;
    uint16_t planes;
    uint16_t bpp;
    int compress;
    int imgsize;
    int bpmx;
    int bpmy;
    int colors;
    int imxtcolors;

    public:
        BMPInfoHeader(){

        }

        BMPInfoHeader(uint16_t  type1,int size1,int reserved1,
                    int offset1,int headersize1,int width1,int height1,
                    uint16_t planes1,uint16_t bpp1,int compress1,int imgsize1,
                    int bpmx1,int bpmy1,int colors1,int imxtcolors1){

                type = type1;
                size = size1;
                reserved = reserved1;
                offset = offset1;
                headersize = headersize1;
                width = width1;
                height = height1;
                planes = planes1;
                bpp = bpp1;
                compress = compress1;
                imgsize = imgsize1;
                bpmx = bpmx1;
                bpmy = bpmy1;
                colors = colors1;
                imxtcolors = imxtcolors1;
        }

        uint16_t getType(){return type;}

        int getSize(){return size;}

        int getReserved(){return reserved;}

        int getOffset(){return offset;}

        int getHeadersize(){return headersize;}

        int getWidth(){return width;}

        int getHeight(){return height;}

        uint16_t getPlanes(){return planes;}

        uint16_t getBpp(){return bpp;}

        int getCompress(){return compress;}

        int getImgsize(){return imgsize;}

        int getBpmx(){return bpmx;}

        int getBpmy(){return bpmy;}

        int getColors(){return colors;}

        int getImxtcolor(){return imxtcolors;}










};
