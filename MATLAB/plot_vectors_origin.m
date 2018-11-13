function plot_vectors_origin(end_points)
  zerovec=zeros(1,size(end_points,2));
  quiver(zerovec,zerovec,end_points(1,:),end_points(2,:),0)
  axis equal
end

